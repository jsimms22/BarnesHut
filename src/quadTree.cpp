#include "../include/quadTree.h"

namespace quadtree
{
    void QuadTree::init_tree(std::vector<particle_sys::Body>& bin, int n)
    // we take an empty bin of particles, and a number of desired particles
    // insert particles into a tree
    // then we build leafs of tree
    {
        if (bin.size() == 0){
            particle_sys::init_particles(bin,n);
        }

        if (this->m_root == nullptr) {
            this->m_root = new Node{bin,Box(),nullptr};
            if (bin.size() > 1) {
                for (auto b : this->m_root->m_bin) {
                    insert(m_root,b);
                }
            }
        }
    }

    void QuadTree::insert(Node* root, particle_sys::Body& b)
    {
        Node* ptr = root;
        if (ptr != nullptr) {
            for (Node* q : ptr->quad) {
                q = new Node(Box(),ptr);
                if (in_boundary(q->m_box,Point{b.x,b.y})) {
                    q->m_bin.push_back(b);
                    ptr = q;
                    insert(ptr,b);
                }
            }
        } else /*if (ptr == nullptr && ptr != this->get_root())*/ {
            std::cout << "something else is happening\n";
        }

    }

    bool in_boundary(Box b, Point p)
    {
        return (p.x >= b.tl.x &&
        p.x <= b.br.x &&
        p.y >= b.br.y &&
        p.y <= b.tl.y);
    }

    // void QuadTree::insert(particle_sys::Body& j, Node* n)
    // /* TODO */
    // {
    //     // if node is NULL, return
    //     if (n == NULL) return;
    //     // current quad cannot contain it, return
    //     if(!in_boundary(Point{j.x,j.y}, *n)) { return; }
    //     // else add body to node
    //     else { n->node_bin.push_back(j); }
    // }

    void print_node_bin(Node* n)
    {
        for (particle_sys::Body b : n->m_bin) {
            std::cout << b.x << ", " << b.y << '\n';
        }
    }
} // namespace quadtree



