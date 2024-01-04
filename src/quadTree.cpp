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
            Box temp = Box(Point{-1.0*_pWidth,_pHeight}, Point{_pWidth,-1.0*_pHeight});
            this->m_root = new Node{bin,temp,nullptr};
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
            for (int i = 0; i < 4; i++) {
                Box temp = create_box(ptr,i);
                ptr->quad[i] = new Node(temp,ptr);
                if (in_boundary(ptr->quad[i]->m_box,Point{b.x,b.y})) {
                    //std::cout << "hello from quad: " << i+1 << '\n';
                    ptr->quad[i]->m_bin.push_back(b);
                    ptr = ptr->quad[i];
                    return;
                }
            }
        } else /*if (ptr == nullptr && ptr != this->get_root())*/ {
            std::cout << "something else is happening\n";
            return;
        }
        return;
    }

    bool in_boundary(Box b, Point p)
    {
        return (p.x >= b.tl.x &&
        p.x <= b.br.x &&
        p.y >= b.br.y &&
        p.y <= b.tl.y);
    }

    Box create_box(Node* parent, int quad) 
    {
        Point _tl, _br;
        switch(quad){
            case 0:
                return Box(parent->m_box.tl,parent->m_box.center);
            case 1:
                _tl = Point{(parent->m_box.tl.x+parent->m_box.br.x)/2, 
                            parent->m_box.tl.y};
                _br = Point{parent->m_box.br.x,
                            (parent->m_box.tl.y+parent->m_box.br.y)/2};
                return Box(_tl,_br);
            case 2:
                _tl = Point{parent->m_box.tl.x,
                            (parent->m_box.tl.y+parent->m_box.br.y)/2};
                _br = Point{(parent->m_box.tl.x+parent->m_box.br.x)/2,
                            parent->m_box.br.y};
                return Box(_tl,_br);
            case 3:
                return Box(parent->m_box.center,parent->m_box.br);
            default:
                return Box(Point{0,1},Point{1,0});
        }
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



