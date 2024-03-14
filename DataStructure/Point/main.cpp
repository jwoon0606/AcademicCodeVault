#include <iostream>
#include "Point.h"

using namespace std;
int main(){
    Point p1, p2;
    p1.init(0,0);
    p2.init(2,3);
    p1.show();
    p2.show();

    cout << "p1.x: " << p1.getX() << '\t';
    cout << "p2.y: " << p2.getY() << endl;
    p1.change_pos(3, 5);
    p1.show();
}