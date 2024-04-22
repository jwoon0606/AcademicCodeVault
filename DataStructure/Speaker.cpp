/*
데이타구조 04분반 22000220 남종운
Reference
- Blog: https://error999.tistory.com/22
*/

#include "Speaker.h"
#include <iostream>
using namespace std;

// default constructor
Speaker::Speaker() : OnOff(false), volume(1) {}

// changes on/off state
void Speaker::PowerOnOff()
{
    OnOff = (OnOff == true) ? false : true;
    volume = (OnOff == true) ? 1 : 0;
}

// increases volume by 1 level(maximum level is level 5)
void Speaker::VolumeUp()
{
    if (volume == 5)
        printf("Volume is arleady Max level 5\n");
    else
        volume += 1;
}

// decrease volume down by 1 level
void Speaker::VolumeDown()
{
    if (volume == 1)
        printf("Volume is arleady MIN level 1\n");
    else
        volume -= 1;
}

// shows if speaker is on or off
bool Speaker::IsOn()
{
    return OnOff;
}

// speaker's status
void Speaker::ShowStatus()
{
    if (OnOff == true)
        printf("Current volume level is %d.\n", volume);
    else
        printf("Speaker is off now.\n");
}

// descructor
Speaker::~Speaker(){};