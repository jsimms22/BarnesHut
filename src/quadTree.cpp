#include "../include/quadTree.h"

namespace quadtree
{
    void QuadTree::init_tree(std::vector<particle_sys::Body>& bin, int n)
    // we take an empty bin of particles, and a number of desired particles
    // insert particles into a tree
    // then we build leafs of tree
    {
        if (bin.size() == 0){
            // try {
                particle_sys::init_particles(bin,n);
            // } catch(const std::exception& e) {
            //     std::cerr << e.what() << '\n';
            // } catch (...) {
            //     std:cerr << "Unknown error when calling my_function in init_tree." << '\n';
            // }
        }
        
        if (this->root == NULL) {
            this->root = new Node{bin,Box(),NULL,NULL,NULL,NULL};
        } else {
            std::cout << "this->root was not NULL. Do something new.\n";
        }
    }

    // bool QuadTree::in_boundary(Point p) const
    // {
    //     return (p.x >= this->root.node_box.p.x &&
    //     p.x <= n.br.x &&
    //     p.y >= n.tl.y &&
    //     p.y <= n.br.y);
    // }

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
        for (particle_sys::Body b : n->node_bin) {
            std::cout << b.x << ", " << b.y << '\n';
        }
    }
} // namespace quadtree



