#ifndef BOX_H
#define BOX_H

#include "point.h"

namespace quadtree
{
    class Box
    {
    public:
        Box() { }

        Box(Point a, Point b) :tl{a}, br{b} 
        {
            if (a.x >= b.x || b.y >= a.y) { std::cout << "box error\n"; }
            center = Point{(a.x+b.x)/2,(a.y+b.y)/2};
            // std::cout << tl << '\n';
            // std::cout << br << '\n';
        }
        
        Point tl;   // top left point of the node's bounds
        Point br;   // bottom right point of the node's bounds
        Point center;
    };
} // quadtree

#endif