#ifndef t_h
#define t_h

class Time
{
    private:
        int hrs;
        int mins;
        int secs;

    public:
        Time();
        Time(int hrs, int mins, int secs);

        void set(int hrs, int mins, int secs);
        void increment();
        void show();
        bool equal(Time t) const;

        ~Time();
};

#endif