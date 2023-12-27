#include "../include/quadTree.h"

namespace quadtree
{
    template <typename T>
    bool QuadTree<T>::in_boundary(Point<T> p) const
    {
        return (p.x >= n.tl.x &&
        p.x <= n.br.x &&
        p.y >= n.tl.y &&
        p.y <= n.br.y);
    }
    
    template <typename T>
    void QuadTree<T>::insert(particle_sys::Body& j, Node<T>* n)
    /* TODO */
    {
        // if node is NULL, return
        if (n == NULL) return;
        // current quad cannot contain it, return
        if(!in_boundary(Point{j.x,j.y}, *n)) { return; }
        // else add body to node
        else { n->node_bin.push_back(j); }
    }
} // namespace quadtree



