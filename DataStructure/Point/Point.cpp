#include "Point.h"
#include <iostream>

void Point:: init(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point:: change_pos(int dist_x,int dist_y)
{
    x = dist_x; 
    y = dist_y;
} 

void Point:: show(){
    std::cout << "x: " << x << '\t' << "y: " << y << std::endl;
}

int Point:: getX(){
    return x;
}

int Point:: getY(){
    return y;
}

Point:: ~Point(){}