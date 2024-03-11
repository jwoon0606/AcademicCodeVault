// client code(containing main function) “main.cpp”
#include "time.h" // specification of the class
int main()
{
    Time currentTime; // Declares two objects of Time
    Time endTime;
    currentTime.Set(17, 58, 2);
    endTime.Set(18, 30, 0);
    currentTime.Show();
    endTime.Show();

    return 0;
}