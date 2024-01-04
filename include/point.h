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

    inline std::ostream& operator<<(std::ostream& os, const Point p)
    {
        os << '{' << p.x << ',' << p.y << '}';
        return os;
    }
} // namespace quadtree
#endif 