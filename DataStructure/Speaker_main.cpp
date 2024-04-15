/*
데이타구조 04분반 22000220 남종운
Reference
- Blog: https://error999.tistory.com/22
*/

#include "Speaker.h"
#include <iostream>
using namespace std;

int main()
{
    // create Speaker class's instance s
    Speaker s;

    // speaker's default status (Power: off)
    cout << "Default status" << endl;
    s.ShowStatus();
    cout << endl;

    // power on
    cout << "Turn on the Speaker" << endl;
    s.PowerOnOff();
    cout << "Power status(On 1, Off 0): " << s.IsOn() << endl;
    cout << endl;

    // increase volume up 5 times
    s.ShowStatus();
    for (int i = 0; i < 5; i++)
    {
        cout << "Try to volume up by 1" << endl;
        s.VolumeUp(); // final VolumeUp is not allowed(MAX volume: 5)
    }
    s.ShowStatus();
    cout << endl;

    // increase volume down 5 times
    for (int i = 0; i < 5; i++)
    {
        cout << "Try to volume down by 1" << endl;
        s.VolumeDown(); // final VolumeDown is not allowed(MIN volume: 1)
    }
    s.ShowStatus();
    cout << endl;

    // turn off the speaker
    cout << "Turn off the Speaker" << endl;
    s.PowerOnOff();
    cout << "Power status(On 1, Off 0): " << s.IsOn() << endl;

    return 0;
}