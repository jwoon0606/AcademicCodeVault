// In Time.cpp
#include "time.h"
#include <iostream>
// Default Constructor
Time::Time() : hrs(0), mins(0), secs(0){}
// parametrized Constructor
Time::Time(int hours, int minutes, int seconds) : hrs(hours), mins(minutes), secs(seconds){}
// Destructor
Time::~Time(){}
void Time::Set(int hours, int minutes, int seconds)
{
    hrs = hours;
    mins = minutes;
    secs = seconds;
}
void Time::Show()
{
    std::cout << hrs << " : " << mins << " : " << secs << std::endl;
}