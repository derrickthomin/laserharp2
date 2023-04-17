// Use this to collect sensor data.
#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include "AudioSetup.h"
#include <list>
#include <Bounce2.h>
#include <Encoder.h>
#include <string>

#include "inputs.h"
#include "Display.h"
#include "AudioSetup.h"
#include "util.h"


// - - - - - - - - - - - - - - - - -  //
//          Hardware Setup            //
// - - - - - - - - - - - - - - - - -  //

#define NUM_STRINGS   14
#define NUM_MUX_PINS  8
#define SENSOR_THRESH 400    // Below this, count the laser as broken

// Laser Sensors (MUX)
#define MUX_CONTROL_S0       28
#define MUX_CONTROL_S1       29
#define MUX_CONTROL_S2       30
#define MUX_1_DATA_PIN       25               // Analog - 1st 8 Sensors
#define MUX_2_DATA_PIN       24               // Analog - last 6 sensors, theremin mode sensor djt- maybe do thremin on another analog pin if avail..
const uint8_t  muxDataPins[2]        = {MUX_1_DATA_PIN, MUX_2_DATA_PIN};
const uint8_t  selectPins[3]         = {MUX_CONTROL_S0, MUX_CONTROL_S1, MUX_CONTROL_S2};

// Encoder
#define ENCODER_DT_PIN       2
#define ENCODER_CLK_PIN      3
#define ENCODER_BTN_PIN      4
Encoder encoder(ENCODER_DT_PIN,ENCODER_CLK_PIN);

// Modulation Photoresistor
#define MOD_PHOTORESISTOR_PIN 14

// Pot 
#define VOLUME_PIN         26  // Slider pot on the back
#define FX_SLIDER_PIN      27  // Slider pot 2 on the back
const uint8_t slidePotPins[2] = {VOLUME_PIN, FX_SLIDER_PIN};
#define SLIDEPOT_CHG_THRESH = 10

// Volume related globals
int             pot_val      = 0; 
uint16_t        theremin_val = 0;
int             pot_vol_prev = 0;
const uint8_t   pot_thresh   = 2;      // How much does the pot analog value need to change to count
float           velocity     = 1;

// Debounce Settings
const uint8_t   debounce_ms  = 10;
const int       DEBUG_millisBetweenPrintout = 500;  // Print to serial this many MS
int             DEBUG_nextMillis = 0;

// Put them in lists
// std::list<int> nav_btn_list      = {NAV_L, NAV_R, NAV_ENTER};
// std::list<int> oct_btn_list      = {BTN_WC, BTN_OCTDOWN, BTN_OCTUP};

// Sensor Tracking
bool   sensorStatePrev[16] = {0};
bool   sensorStateCurrent[16] = {0};
int    photoSensorRaw[16] = {0};
bool   newNotes[16] = {0};
bool   offNotes[16] = {0};
double sens_ontime[16] = {0};
double sens_st_time[16] = {0};
int    fxPhotoresistor = 0;

// slidepots 0 = FX, 1 = Volume
int    slidePots[2] = {0};
int    slidePotsPrev[2] = {0};
bool   slidePotsChanged[2] = {false};

// Encoder
int     encoderCount = 0;
int     encoderCountPrev = 0;
bool    encoderBtn = true;
bool    encoderBtnPrev = true;


// Main input checking function - get raw data
bool    checkAllInputs(void){

  // A - Reset values
  bool haveAnyChanged = false;
  encoderCountPrev = encoderCount;
  encoderBtnPrev   = encoderBtn;

  if (abs(slidePots[0] - slidePotsPrev[0]) > 10)
  {
    slidePotsPrev[0] = slidePots[0];
    slidePotsChanged[0] = true;
  }

  if (abs(slidePots[1] - slidePotsPrev[1]) > 10){
    slidePotsPrev[1] = slidePots[1];
    slidePotsChanged[1] = true;
  }

  for (int idx = 0; idx < 16; idx++){
    newNotes[idx] = false;
    offNotes[idx] = false;
  }

  // B - Get all slider, FX photoresistor, encoder values
  slidePots[0]    = analogRead(slidePotPins[0]);
  slidePots[1]    = analogRead(slidePotPins[1]);
  fxPhotoresistor = analogRead(MOD_PHOTORESISTOR_PIN);
  encoderBtn      = digitalRead(ENCODER_BTN_PIN);
  encoderCount    = encoder.read();

  // C - Loop through all mux pins
  for (uint8_t pin=0; pin<NUM_MUX_PINS; pin++){

    // Setup the loop
    selectMuxPin(pin);    
    delayMicroseconds(5);
    //uint8_t pin2 = pin2;          // Simply pin + number of mux pins (to read both mux outputs at same time)

    // Loop through the 2 mux chips (have to read each for each select mux pin call above)
    int i = 0;
    while (i < 9){
      
      uint8_t idx = pin + i;
      uint8_t muxIdx = 0;
      if (i > 0) muxIdx = 1;

      // 1. - First save off prev photoresistor states
      sensorStatePrev[idx] = sensorStateCurrent[idx];

      // 2. - Now take new readings
      photoSensorRaw[idx]  = analogRead(muxDataPins[muxIdx]);
      
      // 2.1 - Convert analog readings into ON and OFF
      if (photoSensorRaw[idx] < SENSOR_THRESH){
        sensorStateCurrent[idx] = true;
      } else {
        sensorStateCurrent[idx] = false;
      }

      // 2.5  Catch any new notes, update in-flight notes

      // 2.51 - WAS = OFF and NOW = ON...   restart ontime counter. Play new notes, depending on playmode
      if (sensorStateCurrent[idx] && !sensorStatePrev[idx])
      {
        sens_st_time[idx] = millis();
        switch(sound_idx)
        {
          case 0:  // Harp
            break;

          case 1:  // Synth Pad
            newNotes[idx] = true;
            break;

          default:
            break;
        }
      }

      // 2.52 - WAS = ON and NOW = ON...    add to ontime counter
      if (sensorStateCurrent[idx] && sensorStatePrev[idx]) sens_ontime[idx] = (millis() - sens_st_time[idx]);

      // 2.53 - WAS = ON and NOW = OFF...   Play new notes, depending on playmode.
      if (!sensorStateCurrent[idx] && sensorStatePrev[idx]) 
      {
        switch(sound_idx)
        {
          case 0:  // Harp
            newNotes[idx] = true;
            break;

          case 1:  // Synth Pad
            offNotes[idx] = true;
            break;
            
          default:
            break;
        }
      }
      i = i + 8;
    }
  }

  if (millis() > DEBUG_nextMillis){

    DEBUG_nextMillis = millis() + DEBUG_millisBetweenPrintout;
    z__printAllDebugData();

  }
  return haveAnyChanged;
}

// Process the inputs - change volume, fx, etc.
// Sets update screen to TRUE if screen needs a refresh
void processInputs(void){

  // 0.0 - Translate input data into discrete actions to deal with in the next parts
  int8_t direction  = 0;    // Can be 0 = none, -1 = left, 1 = right
  bool btnPress     = false;
  update_display    = false;

  if ((encoderCount > encoderCountPrev) && (encoderCount %2 == 0)) direction = 1;        // Turning encoder to the right
  if ((encoderCount < encoderCountPrev) && (encoderCount %2 == 0)) direction = -1;       // Turning encoder to the left
  if (!encoderBtnPrev && encoderBtn) btnPress = true;

  // 0.5 - If the encoder button is pressed, just loop back around after switching menu context.
  if (btnPress){
    outer_menu = !outer_menu;
    return;
  }

  if (direction == 0 && slidePotsChanged[0] == false && slidePotsChanged[1] == false) return;     // Bail early if we already handled the button and there is no encoder change
  bool dir = util_int_to_bool(direction);

  // 1.0 - Choosing between outer screens, if encoder used
  if (direction != 0 && outer_menu){
    next_screen(direction);
    return;
    } else if (direction != 0){
    
      // 2.0 - Not in the outer screen... deal with settings depending on which we are on
      switch (cur_screen_idx)
      {
        case 0: // Play screen
          break;
        
        case 1: // Sound select
          chg_sound(dir);
          update_sound_sel_screen();
          break;

        case 2: // Reverb level
          chg_rev_time(dir);
          update_rev_screen();
          break;

        case 3: // Theremin Mod Destination
          chg_theremin_mode(dir, true);
          update_theremin_screen();
          break;

        case 4: // Playmode
          chg_playmode(dir);
          update_playmode_screen();
          break;

        default:  
          break;      
      }
  }

  // 3.0 - Deal with slide pots
  if (slidePotsChanged[0]){
    slidePotsChanged[0] = false;
    // update fx
  }
  if (slidePotsChanged[1]){
    slidePotsChanged[1] = false;
    update_volume();
    // update vol.
  }
}

// ------------ Setup / Utility -------------- //

// Pin numbers = 0 thru 7
void selectMuxPin(uint8_t pin)         // Switch all mux inputs
{
  for (int i=0; i<3; i++)
  {
    if (pin & (1<<i))
      digitalWrite(selectPins[i], HIGH);
    else
      digitalWrite(selectPins[i], LOW);
  }
}

void inputSetup(void)
{
  for (int i=0; i<3; i++)             // Set select pins as outputs
  {
    pinMode(selectPins[i], OUTPUT);
    digitalWrite(selectPins[i], HIGH);
  }

  pinMode(ENCODER_BTN_PIN, INPUT_PULLUP);
}


/*
********************* Utility / Debug Functions *******************

  Stuff to help with debugging, testing, etc. 
  Not used in actual functionality

********************************************************************
*/

// Print nicely formatted debug data for EVERYTHING
void z__printAllDebugData(void){
  Serial.println();
  Serial.println();
  Serial.println(" ---------- D    E    B    U    G ----------");
  Serial.println();
  Serial.print("Sensors (raw):      ");
  z__printArrayToSerial(16, photoSensorRaw);
  Serial.println();
  Serial.print("Sensors (on/off):   ");
  z__printArrayToSerial(16, sensorStateCurrent);
  Serial.println();
  Serial.print("Encoder Count:      ");
  Serial.print(encoder.read());
  Serial.println();
  Serial.print("Encoder Btn Now:     ");
  Serial.print(encoderBtn);
  Serial.println();
  Serial.print("Slider Vals (1-2):  ");
  z__printArrayToSerial(2, slidePots);
  Serial.println();
  Serial.print("FX Photoresistor:   ");
  Serial.print(fxPhotoresistor);
  Serial.println();
  Serial.print("Outer Menu?:        ");
  Serial.print(outer_menu);
  Serial.println();
  Serial.print("Theremin Mode IDX:  ");
  Serial.print(theremin_idx);
  Serial.println();

  Serial.println();
  Serial.print("Audio - Peak Readings:  ");
  for (int i = 0; i < 3; i++){
    Serial.print(peaks[i]->read());
    Serial.print("  -  ");
  }
}

// Utility function to help debug array values
void z__printArrayToSerial(uint8_t size, uint16_t array[])
{
    for(uint8_t i = 0; i < size; i++)
    {
    Serial.print(String (array[i]) + " | ");
    }
}

void z__printArrayToSerial(uint8_t size, bool array[])
{
    for(uint8_t i = 0; i < size; i++)
    {
    Serial.print(String (array[i]) + " - ");
    }
}

// Utility function to help debug array values
void z__printArrayToSerial(uint8_t size, int array[])
{
    for(uint8_t i = 0; i < size; i++)
    {
    Serial.print(String (array[i]) + " - ");
    }
}

// Utility function to help debug array values
void z__printArrayToSerial(uint8_t size, int8_t array[])
{
    for(uint8_t i = 0; i < size; i++)
    {
    Serial.print(String (array[i]) + " - ");
    }
}
