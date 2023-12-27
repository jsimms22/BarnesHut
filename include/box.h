#ifndef BOX_H
#define BOX_H

#include "point.h"

namespace quadtree
{
    template <typename T>
    class Box
    {
    public:
        Point<T> tl;   // top left point of the node's bounds
        Point<T> br;   // bottom right point of the node's bounds
    };
} // quadtree

#endif