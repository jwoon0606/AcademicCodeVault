/*
데이타구조 04분반 22000220 남종운
Reference
- Blog: https://error999.tistory.com/22
*/

#ifndef s_h
#define s_h

class Speaker
{
private:
    bool OnOff; // on : true, off : false
    int volume; // level 1 ~ 5

public:
    Speaker(); // default constructor

    void PowerOnOff(); // changes on/off state
    void VolumeUp();   // increases volume by 1 level(maximum level is level 5)
    void VolumeDown(); // decrease volume down by 1 level
    bool IsOn();       // shows if speaker is on or off
    void ShowStatus(); // speaker's status

    ~Speaker(); // descructor
};

#endif