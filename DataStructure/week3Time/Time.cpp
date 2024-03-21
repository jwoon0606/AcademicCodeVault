#include "Time.h"
#include <iostream>
using namespace std;

Time::Time():hrs(0),mins(0),secs(0){}

Time::Time(int hrs, int mins, int secs):hrs(hrs),mins(mins),secs(secs){}

void Time::set(int hrs, int mins, int secs){
    this->hrs = hrs;
    this->mins = mins;
    this->secs = secs;
}

void Time::show(){
    cout<< hrs << ":" << mins<<":" << secs << endl;

}

void Time::increment(){
    this->secs++;
    if(this->secs == 60){
        this->secs = 0;
        this->mins++;
        if(this->mins == 60){
            this->mins = 0;
            this -> hrs++;
            if(this->hrs == 24) this->hrs = 0;
        }//if 60 min
    }//if 60 sec
}

bool Time::equal(Time t) const{
    return( (hrs==t.hrs) && (mins == t.mins) && (secs == t.secs));
}

Time::~Time(){};
/*
 public:
  	Time();
  	Time(int hrs, int mins, int secs);
  	
    void Set(int h, int m, int s);
    void Show();
    
    ~Time();
};

#endif
*/