// Just some utility functions that don't belong anywhere else.
#include "util.h"
#include <Arduino.h>


float util_debug_print_timer = millis();

/*
Change the index but don't allow it to go below 0, or above the max. Loop around to beg or end.
Params:
    upOrDown - True = try to increment. False = Try to decrement.
    &idx     - The value to change
    max      - Max value the IDX can be. Usually size of vector -1. If it is surpassed
            then return 0.
*/
void util_chg_index(bool upOrDown, int8_t &idx, uint8_t max, bool loopOption)
{
    (upOrDown) ? idx++ : idx--;

    // Attemting to go above the max. 
    // if loopption, loop back to 0. Else, just set to max.
    if (idx > max && idx > 0)
    {
        if (loopOption)
        {
            idx= 0;
        } else 
        {
            idx = max;
        }

    }
    
    // Attempting to go below 0 index.
    // if loopption, loop back to Max. Else, just set to 0.
    if (idx < 0)
    {
        if (loopOption)
        {
            idx = max;

        } else {
            idx = 0;
        }
    }
}

// 0 - do nothing
// > 0 - return true
// < 0 - return false
bool util_int_to_bool(int input){
    if (input == 0) return;
    bool output = (input > 0) ? true:false;
    return output;
}