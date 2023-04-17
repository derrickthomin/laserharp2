#pragma once

#include <Arduino.h>
#include <list>
#include <vector>
#include <Bounce2.h>

// Volume Pot
extern int   pot_vol; 
extern uint16_t theremin_val;
extern int   pot_vol_pre;
extern float velocity;

extern const uint8_t pot_thresh;
extern const uint8_t debounce_ms;

#define SENS_1 2
#define SENS_2 3
#define SENS_3 4
#define SENS_4 5
// #define SENS_5 6
// #define SENS_6 7     BROKEN - need to replace. Also need to solder to new pin.., need 7 for shield
// #define SENS_7 8     BROKN - replace 
#define SENS_8 9

// Pots / Theremin
#define VOL 14
#define THEREMIN 15

// Control Buttons
#define BTN_WC 12
#define BTN_OCTDOWN 11
#define BTN_OCTUP 10

// Screen Nav Buttons
#define NAV_L 23
#define NAV_R 21
#define NAV_ENTER 22

// Bounce objects for btns
extern Bounce bounce_btn_wc;
extern Bounce bounce_btn_octdown;
extern Bounce bounce_btn_octup;
extern Bounce bounce_btn_nav_l;
extern Bounce bounce_btn_nav_r;
extern Bounce bounce_btn_nav_enter;

// Put them in lists
extern std::list<int> nav_btn_list;
extern std::list<int> oct_btn_list;               

// Sensor Tracking
extern bool   sensorStatePrev[16];
extern bool   sensorStateCurrent[16];
extern int    photoSensorRaw[16];
extern bool   newNotes[16];
extern bool   offNotes[16] ;
extern double sens_ontime[16];
extern double sens_st_time[16];
extern int    fxPhotoresistor;
extern int    slidePots[2];
extern int    slidePotsPrev[2];
extern bool   slidePotsChanged[2];
extern int    encoderCount;
extern int    encoderCountPrev;
extern bool   encoderBtn;
extern bool   encoderBtnPrev;

bool get_new_notes(void);
bool pot_changed(void);
void process_buttons (void);              // Check for new button vals, returns true if screen needs an update
void check_buttons(void);
void initInputs(void);
bool checkAllInputs(void);
void inputSetup(void);
void processInputs(void);

void selectMuxPin(uint8_t pin);
void z__printAllDebugData(void);
void z__printArrayToSerial(uint8_t size, uint16_t array[]);
void z__printArrayToSerial(uint8_t size, int array[]);
void z__printArrayToSerial(uint8_t size, bool array[]);