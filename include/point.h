#ifndef POINT_H
#define POINT_H

namespace quadtree
{
    template<typename T>
    struct Point
    {
        T x; 
        T y;
        Point() { }
        Point(T _x, T _y) :x{_x}, y {_y} { }
    };

    template<typename T>
    inline bool operator==(Point<T> a, Point<T> b) { return a.x==b.x && a.y==b.y; }

    template<typename T>
    inline bool operator!=(Point<T> a, Point<T> b) { return !(a==b); }

} // namespace quadtree
#endif 