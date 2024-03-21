#include "Time.h"
#include <iostream>

using namespace std;
int main () {
    Time t1, t2(1, 2, 3);
    t1.show(); t2.show();
    t1.set (17, 59, 58); t2.show();
    t1.increment(); t1.increment(); t2.increment();
    t1.show(); t2.show();
    if (t1.equal(t2)==true) cout << "Equals" << endl;
    else cout << "Different" << endl;
    t1.set(1, 1, 60);
}