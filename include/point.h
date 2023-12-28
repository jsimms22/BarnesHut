#ifndef POINT_H
#define POINT_H

namespace quadtree
{
    struct Point
    {
        double x; 
        double y;
        Point() { }
        Point(double _x, double _y) :x{_x}, y {_y} { }
    };

    inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; }

    inline bool operator!=(Point a, Point b) { return !(a==b); }

} // namespace quadtree
#endif 