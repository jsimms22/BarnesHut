#ifndef BOX_H
#define BOX_H

#include "point.h"

namespace quadtree
{
    class Box
    {
    public:
        Box() { }
        Point tl;   // top left point of the node's bounds
        Point br;   // bottom right point of the node's bounds
    };
} // quadtree

#endif