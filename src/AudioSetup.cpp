// Functions for setting up audio objects and such

#include <Arduino.h>
#include <Audio.h>
#include <Wire.h>
#include <string>
#include <SerialFlash.h>
#include "AudioSetup.h"
#include "notes_and_chords.h"
#include "Display.h"
#include "util.h"
#include "Inputs.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthKarplusStrong  string5;        //xy=69.64289855957031,298.7976131439209
AudioSynthKarplusStrong  string1;        //xy=74.11909103393555,131.89286041259766
AudioSynthKarplusStrong  string6;        //xy=73.64289855957031,338.7976131439209
AudioSynthKarplusStrong  string14; //xy=72.5,681.6548309326172
AudioSynthKarplusStrong  string2;        //xy=74.78575897216797,179.22619819641113
AudioSynthKarplusStrong  string3;        //xy=74.78575897216797,217.22619819641113
AudioSynthKarplusStrong  string13; //xy=73.5,642.6548309326172
AudioSynthKarplusStrong  string10; //xy=74.5000228881836,524.3690462112427
AudioSynthKarplusStrong  string11; //xy=74.5000228881836,562.3690462112427
AudioSynthKarplusStrong  string7;        //xy=75.64289855957031,385.7976131439209
AudioSynthKarplusStrong  string4;        //xy=76.78575897216797,254.22619819641113
AudioSynthKarplusStrong  string8;        //xy=76.64289855957031,435.7976131439209
AudioSynthKarplusStrong  string9; //xy=76.9285888671875,483.9404821395874
AudioSynthKarplusStrong  string12; //xy=76.5000228881836,599.3690462112427
AudioSynthWaveform       waveform13; //xy=81.21434020996094,1488.2262363433838
AudioSynthWaveform       waveform14; //xy=81.21434020996094,1534.2262363433838
AudioSynthWaveform       waveform11; //xy=84.21434020996094,1396.2262363433838
AudioSynthWaveform       waveform12; //xy=84.21434020996094,1441.2262363433838
AudioSynthWaveform       waveform9; //xy=85.21434020996094,1308.2262363433838
AudioSynthWaveform       waveform10; //xy=85.21434020996094,1350.2262363433838
AudioSynthWaveform       waveform8; //xy=86.21434020996094,1264.2262363433838
AudioSynthWaveform       waveform3; //xy=87.21434020996094,1048.2262363433838
AudioSynthWaveform       waveform7; //xy=88.21434020996094,1220.2262363433838
AudioSynthWaveform       waveform4; //xy=89.21434020996094,1090.2262363433838
AudioSynthWaveform       waveform5; //xy=89.21434020996094,1138.2262363433838
AudioSynthWaveform       waveform6; //xy=89.21434020996094,1180.2262363433838
AudioSynthWaveform       waveform1;      //xy=91.21434020996094,960.2262363433838
AudioSynthWaveform       waveform2; //xy=91.21434020996094,1006.2262363433838
AudioEffectEnvelope      env_string_14; //xy=236.5,679.6548309326172
AudioEffectEnvelope      env_string_2;      //xy=238.78575897216797,177.22619819641113
AudioEffectEnvelope      env_string_5;      //xy=238.6428985595703,301.7976131439209
AudioEffectEnvelope      env_string_7;      //xy=238.6428985595703,388.7976131439209
AudioEffectEnvelope      env_string_1;      //xy=239.78575134277344,133.55952072143555
AudioEffectEnvelope      env_string_10; //xy=238.5000228881836,522.3690462112427
AudioEffectEnvelope      env_string_13; //xy=238.5,642.6548309326172
AudioEffectEnvelope      env_string_8;      //xy=239.6428985595703,436.7976131439209
AudioEffectEnvelope      env_string_9; //xy=239.5000228881836,485.3690462112427
AudioEffectEnvelope      env_string_3;      //xy=241.78575897216797,217.22619819641113
AudioEffectEnvelope      env_string_11; //xy=241.5000228881836,562.3690462112427
AudioEffectEnvelope      env_string_6;      //xy=242.6428985595703,346.7976131439209
AudioEffectEnvelope      env_string_4;      //xy=243.78575897216797,254.22619819641113
AudioEffectEnvelope      env_string_12; //xy=243.5000228881836,599.3690462112427
AudioEffectEnvelope      env_pad_13; //xy=251.21434020996094,1489.2262363433838
AudioEffectEnvelope      env_pad_14; //xy=251.21434020996094,1533.2262363433838
AudioEffectEnvelope      env_pad_12; //xy=252.21434020996094,1442.2262363433838
AudioEffectEnvelope      env_pad_8; //xy=254.21434020996094,1263.2262363433838
AudioEffectEnvelope      env_pad_9; //xy=254.21434020996094,1308.2262363433838
AudioEffectEnvelope      env_pad_5; //xy=256.2143440246582,1138.8928260803223
AudioEffectEnvelope      env_pad_11; //xy=255.54766845703125,1394.892837524414
AudioEffectEnvelope      env_pad_6; //xy=256.5476760864258,1179.892910003662
AudioEffectEnvelope      env_pad_7; //xy=257.21434020996094,1219.2262363433838
AudioEffectEnvelope      env_pad_4; //xy=258.54767990112305,1090.8929061889648
AudioEffectEnvelope      env_pad_10; //xy=259.21434020996094,1350.2262363433838
AudioEffectEnvelope      env_pad_2; //xy=260.88100814819336,1005.2262358665466
AudioEffectEnvelope      env_pad_3; //xy=260.8810005187988,1049.2261972427368
AudioEffectEnvelope      env_pad_1; //xy=268.21434020996094,958.2262363433838
AudioMixer4              mixer_strings_1;         //xy=426.78575897216797,192.22619819641113
AudioMixer4              mixer_strings_2;         //xy=426.6428985595703,371.7976131439209
AudioMixer4              mixer_strings_4; //xy=435.92858123779297,672.7976970672607
AudioMixer4              mixer_strings_3; //xy=445.5000228881836,540.3690462112427
AudioMixer4              mixer_pad_4; //xy=447.21436309814453,1509.6547470092773
AudioMixer4              mixer_pad_3; //xy=452.7857856750488,1372.65478515625
AudioMixer4              mixer_pad_1; //xy=456.21434020996094,1035.2262363433838
AudioMixer4              mixer_pad_2; //xy=456.21434020996094,1199.2262363433838
AudioMixer4              mixer_strings_all;         //xy=710.9286422729492,480.5119152069092
AudioMixer4              mixer_pad_all; //xy=714.2143402099609,1266.2262363433838
AudioMixer4              mixerFXDelay; //xy=795.0714492797852,1022.22629737854
AudioMixer4              mixerFXVerb;    //xy=805.035774230957,840.2262020111084
AudioEffectDelay         delay1;         //xy=999.3572044372559,1022.226053237915
AudioEffectReverb        reverb1;        //xy=1001.2858734130859,866.1904964447021
AudioAnalyzePeak         peak_mixermaster;          //xy=1008.2144470214844,267.44044303894043
AudioEffectFreeverb      freeverb1;      //xy=1008.6072158813477,821.4047384262085
AudioAnalyzePeak         peak_mixerstringsall;          //xy=1015.0715789794922,232.08332777023315
AudioAnalyzePeak         peak_mixerstrings1;          //xy=1016.9286422729492,194.08334159851074
AudioMixer4              mixerFXDelay_post_1; //xy=1220.9047546386719,995.5595474243164
AudioMixer4              mixerFXDelay_post_2; //xy=1220.9047088623047,1048.8929061889648
AudioMixer4              mixerMaster;    //xy=1258.499843597412,789.2977275848389
AudioMixer4              mixerFXDelay_post_3; //xy=1450.0000610351562,1029.9999809265137
AudioSynthWaveform       LFO1;           //xy=1495.4524765014648,745.0118789672852
AudioFilterStateVariable filterMaster;   //xy=1506.880958557129,791.5833282470703
AudioMixer4              mixerFXMaster1; //xy=1691.6662902832031,946.6666831970215
AudioOutputI2S           i2s1;           //xy=1724.4524002075195,791.7261867523193
AudioConnection          patchCord1(string5, env_string_5);
AudioConnection          patchCord2(string1, env_string_1);
AudioConnection          patchCord3(string6, env_string_6);
AudioConnection          patchCord4(string14, env_string_14);
AudioConnection          patchCord5(string2, env_string_2);
AudioConnection          patchCord6(string3, env_string_3);
AudioConnection          patchCord7(string13, env_string_13);
AudioConnection          patchCord8(string10, env_string_10);
AudioConnection          patchCord9(string11, env_string_11);
AudioConnection          patchCord10(string7, env_string_7);
AudioConnection          patchCord11(string4, env_string_4);
AudioConnection          patchCord12(string8, env_string_8);
AudioConnection          patchCord13(string9, env_string_9);
AudioConnection          patchCord14(string12, env_string_12);
AudioConnection          patchCord15(waveform13, env_pad_13);
AudioConnection          patchCord16(waveform14, env_pad_14);
AudioConnection          patchCord17(waveform11, env_pad_11);
AudioConnection          patchCord18(waveform12, env_pad_12);
AudioConnection          patchCord19(waveform9, env_pad_9);
AudioConnection          patchCord20(waveform10, env_pad_10);
AudioConnection          patchCord21(waveform8, env_pad_8);
AudioConnection          patchCord22(waveform3, env_pad_3);
AudioConnection          patchCord23(waveform7, env_pad_7);
AudioConnection          patchCord24(waveform4, env_pad_4);
AudioConnection          patchCord25(waveform5, env_pad_5);
AudioConnection          patchCord26(waveform6, env_pad_6);
AudioConnection          patchCord27(waveform1, env_pad_1);
AudioConnection          patchCord28(waveform2, env_pad_2);
AudioConnection          patchCord29(env_string_14, 0, mixer_strings_4, 1);
AudioConnection          patchCord30(env_string_2, 0, mixer_strings_1, 1);
AudioConnection          patchCord31(env_string_5, 0, mixer_strings_2, 0);
AudioConnection          patchCord32(env_string_7, 0, mixer_strings_2, 2);
AudioConnection          patchCord33(env_string_1, 0, mixer_strings_1, 0);
AudioConnection          patchCord34(env_string_10, 0, mixer_strings_3, 1);
AudioConnection          patchCord35(env_string_13, 0, mixer_strings_4, 0);
AudioConnection          patchCord36(env_string_8, 0, mixer_strings_2, 3);
AudioConnection          patchCord37(env_string_9, 0, mixer_strings_3, 0);
AudioConnection          patchCord38(env_string_3, 0, mixer_strings_1, 2);
AudioConnection          patchCord39(env_string_11, 0, mixer_strings_3, 2);
AudioConnection          patchCord40(env_string_6, 0, mixer_strings_2, 1);
AudioConnection          patchCord41(env_string_4, 0, mixer_strings_1, 3);
AudioConnection          patchCord42(env_string_12, 0, mixer_strings_3, 3);
AudioConnection          patchCord43(env_pad_13, 0, mixer_pad_4, 0);
AudioConnection          patchCord44(env_pad_14, 0, mixer_pad_4, 1);
AudioConnection          patchCord45(env_pad_12, 0, mixer_pad_3, 3);
AudioConnection          patchCord46(env_pad_8, 0, mixer_pad_2, 3);
AudioConnection          patchCord47(env_pad_9, 0, mixer_pad_3, 0);
AudioConnection          patchCord48(env_pad_5, 0, mixer_pad_2, 0);
AudioConnection          patchCord49(env_pad_11, 0, mixer_pad_3, 2);
AudioConnection          patchCord50(env_pad_6, 0, mixer_pad_2, 1);
AudioConnection          patchCord51(env_pad_7, 0, mixer_pad_2, 2);
AudioConnection          patchCord52(env_pad_4, 0, mixer_pad_1, 3);
AudioConnection          patchCord53(env_pad_10, 0, mixer_pad_3, 1);
AudioConnection          patchCord54(env_pad_2, 0, mixer_pad_1, 1);
AudioConnection          patchCord55(env_pad_3, 0, mixer_pad_1, 2);
AudioConnection          patchCord56(env_pad_1, 0, mixer_pad_1, 0);
AudioConnection          patchCord57(mixer_strings_1, 0, mixer_strings_all, 0);
AudioConnection          patchCord58(mixer_strings_1, peak_mixerstrings1);
AudioConnection          patchCord59(mixer_strings_2, 0, mixer_strings_all, 1);
AudioConnection          patchCord60(mixer_strings_4, 0, mixer_strings_all, 3);
AudioConnection          patchCord61(mixer_strings_3, 0, mixer_strings_all, 2);
AudioConnection          patchCord62(mixer_pad_4, 0, mixer_pad_all, 3);
AudioConnection          patchCord63(mixer_pad_3, 0, mixer_pad_all, 2);
AudioConnection          patchCord64(mixer_pad_1, 0, mixer_pad_all, 0);
AudioConnection          patchCord65(mixer_pad_2, 0, mixer_pad_all, 1);
AudioConnection          patchCord66(mixer_strings_all, 0, mixerFXVerb, 0);
AudioConnection          patchCord67(mixer_strings_all, 0, mixerMaster, 0);
AudioConnection          patchCord68(mixer_strings_all, peak_mixerstringsall);
AudioConnection          patchCord69(mixer_strings_all, 0, mixerFXDelay, 0);
AudioConnection          patchCord70(mixer_pad_all, 0, mixerFXVerb, 1);
AudioConnection          patchCord71(mixer_pad_all, 0, mixerMaster, 1);
AudioConnection          patchCord72(mixer_pad_all, 0, mixerFXDelay, 1);
AudioConnection          patchCord73(mixerFXDelay, delay1);
AudioConnection          patchCord74(mixerFXVerb, reverb1);
AudioConnection          patchCord75(mixerFXVerb, freeverb1);
AudioConnection          patchCord76(delay1, 0, mixerFXDelay_post_1, 0);
AudioConnection          patchCord77(delay1, 1, mixerFXDelay_post_1, 1);
AudioConnection          patchCord78(delay1, 2, mixerFXDelay_post_1, 2);
AudioConnection          patchCord79(delay1, 3, mixerFXDelay_post_1, 3);
AudioConnection          patchCord80(delay1, 4, mixerFXDelay_post_2, 0);
AudioConnection          patchCord81(delay1, 5, mixerFXDelay_post_2, 1);
AudioConnection          patchCord82(delay1, 6, mixerFXDelay_post_2, 2);
AudioConnection          patchCord83(delay1, 7, mixerFXDelay_post_2, 3);
AudioConnection          patchCord84(reverb1, 0, mixerMaster, 2);
AudioConnection          patchCord85(freeverb1, 0, mixerMaster, 3);
AudioConnection          patchCord86(freeverb1, 0, mixerFXMaster1, 0);
AudioConnection          patchCord87(mixerFXDelay_post_1, 0, mixerFXDelay_post_3, 0);
AudioConnection          patchCord88(mixerFXDelay_post_2, 0, mixerFXDelay_post_3, 1);
AudioConnection          patchCord89(mixerMaster, 0, filterMaster, 0);
AudioConnection          patchCord90(mixerMaster, peak_mixermaster);
AudioConnection          patchCord91(mixerFXDelay_post_3, 0, mixerFXMaster1, 1);
AudioConnection          patchCord92(LFO1, 0, filterMaster, 1);
AudioConnection          patchCord93(filterMaster, 0, i2s1, 0);
AudioConnection          patchCord94(filterMaster, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1325.4285888671875,208.61904335021973
// GUItool: end automatically generated code


// Tracking Vars related to audio stuff
int8_t    sound_idx        = 0;
uint8_t   env_idx          = 0;
int8_t    scale_idx        = 0;
int8_t    octave_current   = 3; 
int8_t    rev_lvl_idx      = 0;
int8_t    playmode_idx     = 0;
int8_t    theremin_idx     = 1;              // Default to Filter           
int       reverb_time      = 0;     
bool      theremin_calibrated = false;
bool      playmode_chord_posorneg = true;    // 
#define   NUM_STRINGS 14  // how many sensors / strings we have. 

// Default ADSR param settings.
int       attackParam      = 0;
int       decayParam       = 50;
float     sustainParam     = 1;
int       releaseParam     = 500;

// Theremin initial values
int16_t therValMax = 20;
int16_t therValMin = 800;
float   ther_a = 1/((float)therValMax - (float)therValMin);
float   ther_b = 1 - ther_a * therValMax;

// Pointer Arrays - Voices / Envelopes
AudioSynthKarplusStrong *string[14]       = {&string1, &string2, &string3, &string4, &string5, &string6, &string7, &string8, &string9,
                                               &string10, &string11, &string12, &string13, &string14};
AudioEffectEnvelope     *envelope[14]     = {&env_string_1, &env_string_2, &env_string_3, &env_string_4, &env_string_5, &env_string_6, &env_string_7, &env_string_8,
                                               &env_string_9, &env_string_10, &env_string_11, &env_string_12, &env_string_13, &env_string_14};
AudioEffectEnvelope     *envelope_pad[14] = {&env_pad_1, &env_pad_2, &env_pad_3, &env_pad_4, &env_pad_5, &env_pad_6, &env_pad_7, &env_pad_8,
                                               &env_pad_9, &env_pad_10, &env_pad_11, &env_pad_12, &env_pad_13, &env_pad_14};
AudioSynthWaveform      *pad[14]          = {&waveform1, &waveform2, &waveform3, &waveform4, &waveform5, &waveform6, &waveform7, &waveform8, &waveform9,
                                               &waveform10,&waveform11,&waveform12,&waveform13,&waveform14};
AudioMixer4             *SubMixers[10]    = {&mixer_strings_1, &mixer_strings_2, &mixer_strings_3, &mixer_strings_4, &mixer_strings_all, 
                                               &mixer_pad_1, &mixer_pad_2, &mixer_pad_3, &mixer_pad_4, &mixer_pad_all};
AudioAnalyzePeak        *peaks[3]         = {&peak_mixerstrings1, &peak_mixerstringsall, &peak_mixermaster};

// ------- NOTE STUFF ------------ //
std::vector<float> noteList  = {C1_NT, Cs1_NT, D1_NT, Ds1_NT, E1_NT, F1_NT, Fs1_NT, G1_NT, Gs1_NT, A1_NT, As1_NT, B1_NT,C1_NT*2, Cs1_NT*2};
std::vector<float> scaleCmaj = {C1_NT, D1_NT, E1_NT, F1_NT, G1_NT, A1_NT, B1_NT, C1_NT * 2, D1_NT * 2, E1_NT * 2, F1_NT * 2, G1_NT * 2, A1_NT * 2, B1_NT * 2};
std::vector<float> scaleDmaj = {D1_NT, E1_NT, Fs1_NT, G1_NT, A1_NT, B1_NT, Cs1_NT * 2, D1_NT * 2,E1_NT *2, Fs1_NT *2, G1_NT*2, A1_NT*2, B1_NT*2, Cs1_NT * 4};
std::vector<float> scaleDmin = {D1_NT, E1_NT, F1_NT, G1_NT, A1_NT, As1_NT,  C1_NT * 2, D1_NT * 2, E1_NT*2, F1_NT*2, G1_NT*2, A1_NT*2, As1_NT*2};
std::vector<std::vector<float>> scales = {scaleCmaj, scaleDmaj, scaleDmin};

// And also save the names of the scales.
const char * scale_names[3] = {"Cmaj", "Dmaj", "Dmin"};

// Track stuff for diff playmodes
std::vector<uint32_t> playmodeMsBetween      = {500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500};
std::vector<uint32_t> playmodeLastHit        = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
std::vector<int>      playmodeChordIDXNext   = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};

// Initialize audio stuff for teensy audio lib
void initAudio(void){

  // audio library init
  AudioMemoryUsageMaxReset();
  AudioMemory(24);  

  // Turn down reverb mixer gain to avoid noise.
  mixerFXVerb.gain(0,0.2);
  mixerFXVerb.gain(1,0);
  mixerFXVerb.gain(2,0);
  mixerFXVerb.gain(3,0);
  mixerMaster.gain(2, 0.3);
  mixerMaster.gain(3, 0.1); // DJT - FREEVERB. Messs with me later.
  mixerMaster.gain(0, 0.3);
  // freeverb1.roomsize(0.9);
  // freeverb1.damping(0.2);

  for (int i=0; i < 10; i++){
    for (int channel = 0; channel < 4; channel++){
      SubMixers[i] -> gain(channel,0.75);
    }
  }

  // Init LFO + Filter
  // LFO1.begin(0.001, 2, WAVEFORM_SINE); 
  filterMaster.frequency(15000);   
  filterMaster.resonance(1.1);

  
  // assign initial envelope parameters - Strings
  for (int i=0; i < NUM_STRINGS; i++)
  {
    envelope[i] -> delay(0);
    envelope[i] -> attack(attackParam);    
    envelope[i] -> hold(0);                
    envelope[i] -> decay(decayParam);      
    envelope[i] -> sustain(sustainParam);  
    envelope[i] -> release(releaseParam);    
  }

  // assign initial envelope parameters - Pad
  for (int i=0; i < NUM_STRINGS; i++)
  {
    envelope_pad[i] -> delay(0);
    envelope_pad[i] -> attack(attackParam);    
    envelope_pad[i] -> hold(0);                
    envelope_pad[i] -> decay(decayParam);      
    envelope_pad[i] -> sustain(sustainParam);  
    envelope_pad[i] -> release(releaseParam);    
  }

  init_waveforms();
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.7);
  AudioInterrupts();
}

// Set all waveforms to triangle to start
void init_waveforms(void){
  for (int i=0; i < NUM_STRINGS; i++){
    pad[i] -> begin(1, current_notes[i], WAVEFORM_TRIANGLE);
  }}

// next scale in the list
void chg_scale(void){
  util_chg_index(true, scale_idx, scales.size()-1);
  current_notes = scales[scale_idx];                      // Set to new scale
  return;
}

// Go to next or prev sound in the list, and perform any necessary setup 
void chg_sound(bool upOrDown){
  util_chg_index(upOrDown, sound_idx, screen_sound_select.size()-1);
  init_envelope();                                 
}

// Update reverb time
void chg_rev_time(bool upOrDown){
  int rev_time_new = 0;
  util_chg_index(upOrDown, rev_lvl_idx, screen_verb_lvl.size()-1, false);

  switch(rev_lvl_idx)
  {
    case 0: // off
      rev_time_new = 0;
      mixerMaster.gain(2,0);    // Turn off reverb mixer master input
      break;

    case 1: // Low
      rev_time_new = 200;
      mixerMaster.gain(2,0.3);
      break;

    case 2: // Med 
      rev_time_new = 1000;
      mixerMaster.gain(2, 0.4);  // MAKE IT A LIL LOUDER
      break;

    case 3: // High
      rev_time_new = 5000; 
      mixerMaster.gain(2,2);  // MAKE IT LOUDER STILL
      break;

  }

  reverb1.reverbTime(rev_time_new);
  return;
}

void chg_rev_time(int upOrDown){
  if (upOrDown == 0) return;
  chg_rev_time(util_int_to_bool(upOrDown));
}

// Change theremin mode stuff
void chg_theremin_mode(bool upOrDown=true, bool skipCalibration = false){

  util_chg_index(upOrDown, theremin_idx, screen_theremin.size()-1);

  if (!theremin_calibrated && !skipCalibration)
  {
    run_theremin_calibration();  
    theremin_calibrated = true;  
  }
  switch (theremin_idx)
  {
    case 0:  // off
      //
      break;
    
    case 1:  // Map to Filter
      //
      break;
    
    case 2:  // Map to Reverb
      //
      break;
  }          

}

// Toggle playmodes
void chg_playmode(bool upOrDown=true)
{
  util_chg_index(upOrDown, playmode_idx, screen_playmode.size()-1);                                 
}

// Update envelopes based on sound selected
bool update_envelope(uint8_t idx, uint8_t env_idx)
{

    switch(sound_idx) 
    {
      case 0: // String sound
        envelope[env_idx] -> release(releaseMin + (sens_ontime[idx] * 2));
        break;
      
      // case 1: // Drum sound
      //   envelope[env_idx] -> release(releaseMin + (sensorOntime[idx] * 2));
      //   break;

      //   case 2: // Synth sound
      //     envelope_pad[env_idx] -> release(releaseMin + (sens_ontime[idx] * 2));
      //     break;
    }
}

// Update envelopes based on sound selected
void update_volume(void)
{
  float volume;

  // Base velocity based on velocity pot
  volume = (static_cast<float>(slidePots[1]) / 1024);
  mixerMaster.gain(0, volume);
  mixerMaster.gain(1, volume);
  mixerMaster.gain(2, volume);
  mixerMaster.gain(3, volume);
  return;
}

// Set initial & constant env values based on the sound we are on.
void init_envelope(void)
{
  for (int i = 0; i < NUM_STRINGS; i++)
  {
    switch(sound_idx)
    {
      case 0: // String sound
        envelope[i] -> attack(attackParam);
      break;

      case 1: // Drum sound
        envelope[i] -> attack(attackParam);
      break;

      case 2: // Synth sound
        envelope[i] -> attack(3000);
        envelope[i] -> decay(3000);
        envelope[i] -> release(3000);
      break;
    }
  }
}

// Get the high and low values of theremin sensor to calibrate.
void run_theremin_calibration(bool skipCalibration = false)
{

  if (skipCalibration) return;

  // Show user what's going on
  display.clearDisplay();
  display.setCursor(0, 2);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setTextWrap(true);
  display.println("Running Theremin Calibration...");
  display.display();

  delay(1500);
  display.clearDisplay();
  display.setCursor(0, 2);
  display.println("Cover & uncover");
  display.println("sensor 8");
  display.println("when you see GO..");
  display.display();

  delay(3000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(2,2);
  display.println("GO!");
  display.display();

  display.setTextSize(1);
  display.setCursor(20,20);
  display.println("MAX: ");
  display.setCursor(20,30);
  display.println("MIN: ");


  float calibration_timer = millis();
  float calibration_time = 5000;   
  therValMax = 0;
  therValMin = 5000;                    // Set to crazy values to ensure we update with sensor info.  

  // Find min and max
  while (millis() - calibration_timer < calibration_time)
  {
    int16_t cur_ther_val = analogRead(THEREMIN);
    if (cur_ther_val > therValMax) therValMax = cur_ther_val;     
    if (cur_ther_val < therValMin) therValMin = cur_ther_val;

    display.fillRect(70, 0, 100, 100, BLACK);
    display.setCursor(70, 20);
    display.println(therValMax);
    display.setCursor(70, 30);
    display.println(therValMin);
    display.display();
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,20);
  display.println("Calibration Complete");
  display.display();

  delay(2000);
  display.clearDisplay();
  display.drawRoundRect(0,0,SCREEN_WIDTH,16,10,WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(25, 5);
  display.println("Theremin Mode");

  ther_a = 1/((float)therValMax - (float)therValMin);
  ther_b = 1 - ther_a * therValMax;

  // DEBUG INFO
  // Serial.println("theremin calibration complete");
  // Serial.println("------------------------------");
  // Serial.println("Theremin Value Max:    ");
  // Serial.println(therValMax);
  // Serial.println("Theremin Value Min:    ");
  // Serial.println(therValMin);
}

// Update values based on theremin mode.
void update_theremin_fx(void)
{
  float theremin_mult = ther_a * fxPhotoresistor + ther_b;
  // float volume;
  float rtime;
  float gain;

  switch (theremin_idx)
{
    case 1:   // Update Filter
      int freq = 18000 - (theremin_mult * 18000);
      filterMaster.frequency(freq);
      break;

    case 3:   // Update reverb 
      rtime = 500 * (1 + (1 - theremin_mult));    // Less light = higher mult
      gain = (1 - theremin_mult) * 1.2;

      reverb1.reverbTime(rtime);
      mixerMaster.gain(2, gain);  // MAKE IT A LIL LOUDER
      break;
  }
}

// Manage playmode stuff
void update_playmode_hits(int idx, bool init = false)
{
  //Serial.println(playmode_idx);
  if (init)
  {
    playmodeLastHit[idx] = 0;
    playmodeChordIDXNext[idx] = idx;
    playmodeMsBetween[idx] = 500;
    return;
  }

  switch (playmode_idx)
  {
    case 0:  // Playmode = Standard
      //
      break;

    case 1:  // Playmopde = tremelo
      Serial.println(millis() - playmodeLastHit[idx]);
      Serial.println(playmodeMsBetween[idx]);
      if (playmodeMsBetween[idx] < (millis() - playmodeLastHit[idx]))
      {
        playmodeLastHit[idx] = millis();
        playmodeMsBetween[idx] = playmodeMsBetween[idx] - (playmodeMsBetween[idx]/4);

        if (playmodeMsBetween[idx] < 100) playmodeMsBetween[idx] = 100 - (rand() % 25);    // Dont play TOO fast

        newNotes[idx] = true;
      }
      break;
    
    case 2:  // playmode = chords

      if (playmodeMsBetween[idx] < (millis() - playmodeLastHit[idx]))
      {
        playmodeLastHit[idx] = millis();
        playmodeMsBetween[idx] = playmodeMsBetween[idx] - (playmodeMsBetween[idx]/7);

        if (playmodeMsBetween[idx] < 100) playmodeMsBetween[idx] = 100 - (rand() % 25);

        if (playmode_chord_posorneg) playmodeChordIDXNext[idx]++;
        if (!playmode_chord_posorneg) playmodeChordIDXNext[idx]--;
        if (playmodeChordIDXNext[idx] > 7)
        {
          playmodeChordIDXNext[idx] = 7;
          playmode_chord_posorneg = false;
        }

        if (playmodeChordIDXNext[idx] < 0)
        {
          playmodeChordIDXNext[idx] = 0;
          playmode_chord_posorneg = true;
        }

        newNotes[playmodeChordIDXNext[idx]] = true;
        // playmode_chord_idx_add[idx]++;

      }
      break;
    }
}