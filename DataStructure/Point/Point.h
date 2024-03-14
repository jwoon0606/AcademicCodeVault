#ifndef POINT_H
#define POINT_H

class Point // Point.h
{
    private:
        int x;
        int y;

    public:
        void init(int x, int y);
        void change_pos(int dist_x, int dist_y);
        void show();
        int getX();
        int getY();
        ~Point();
};

#endif