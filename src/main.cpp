#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <list>
#include <vector>
#include <cmath>
#include <string>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Bounce2.h>
#include <MIDI.h>

#include "notes_and_chords.h"     // All of the note definitions and such
#include "bitmaps.h"              // Bitmaps for screen
#include "AudioSetup.h"
#include "Display.h"
#include "Inputs.h"

// - - - - - - - - - - - - - - - - -  //
// Constants / Defaults / Global Vars //
// - - - - - - - - - - - - - - - - -  //
const uint8_t   loop_delay = 5;                     // Delay in ms between checking sensors.
uint8_t         next_reading = millis();            // Track when to take next reading. Prob split this up for diff checks.
const int       midi_channel = 1;
#define NUM_STRINGS 14 // djt - combine this from the one in audiosetupeventually

// Notes
std::vector<float> current_notes = scales[scale_idx];           // Maintain this list of 14

// - - - - - - - - - - - - - - - - -  //
//        Function Definitions        //
// - - - - - - - - - - - - - - - - -  //
bool pot_changed(void);

// - - - - - - - - - - - - - - - - -  //
//              Setup                 //
// - - - - - - - - - - - - - - - - -  //
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

void setup() {

  Serial.begin(115200);

  // audio library init
  initAudio();
  initDisplay();                  
  inputSetup();
  MIDI.begin();

  Serial.println("IN SETUP");
}

// //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// //                                                                                                //
// //                                                                                                //
// //                                    M A I N    L O O P                                          //
// //                                  ----------------------                                        //
// //                                  ----------------------                                        //
// //                                                                                                //
// //<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void loop() {

  // Check buttons
  // check_buttons();                  // Get updated button statuses
  // process_buttons();                // Change values and stuff based on btns and screen. Set screen update flag.
  // update_screen();                  // Update the screen based on what we are on, etc etc.
  // update_volume();                  // Prob don't need to do this full speeed.. but will do so until it's a real problem

  // Only check every 10 ms or so
  if (millis() > next_reading)
  {
     next_reading = millis() + loop_delay;
     checkAllInputs();                           // Get the current vals, and tell us if anything changed & reset prev values
     processInputs();

    if (theremin_idx > 0) update_theremin_fx();     // Update params based on theremin if using theremin mode.

    // Main Note Loop
    for (int idx = 0; idx < 14; idx++){
      // env_idx = idx + (sound_idx * 8);
      if (newNotes[idx])
      {
        float note = (pow(2, octave_current)) * current_notes[idx];  // Calc note freq based on octave & current note list
        // update_envelope(idx, env_idx);

        switch(sound_idx)
        {
          case 0: // String sound
            string[idx] -> noteOn(note,1.0f);
            envelope[idx] -> noteOn();
            break;

          case 2: // Synth sound
            pad[idx] -> frequency(note);
            envelope_pad[idx] -> noteOn();
            break;
        }
      } // Turn off the note

      else if (offNotes[idx])
      
      {
        envelope_pad[idx] -> noteOff();
        envelope[idx] -> noteOff();
      }
    }
  }
}

// !!!!!!!!!! TESTING MAIN LOOP !!!!!!!!!!

// void loop(){
//   checkAllInputs();
//   delayMicroseconds(1000);

// //  int note;
// //   for (note=10; note <= 127; note++) {
// //     Serial.println(analogRead(14));
// //     MIDI.sendNoteOn(note, 100, midi_channel);
// //     delay(200);
// //     MIDI.sendNoteOff(note, 100, midi_channel);
// //   }
// //   delay(2000);
// }