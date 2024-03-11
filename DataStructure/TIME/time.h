#ifndef TIME_H
#define TIME_H

class Time // Time.h
{
private: // 3 data members
    int hrs;
    int mins;
    int secs;

public:
    Time(); // Default constructor
    // Not generated autoamatically
    // when there is parameterized constructor
    // Parameterized constructor
    Time(int hours, int minutes, int seconds);
    ~Time(); // Destructor
    void Set(int hours, int minutes, int seconds);
    void Show();
};

#endif