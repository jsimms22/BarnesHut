#ifndef QUADTREE_H
#define QUADTREE_H

#include<memory>
#include "body.h"
#include "point.h"
#include "box.h"

namespace quadtree
{
    // class Node
    // {
    //     vector<Body> node_bin;
    //     bool filled;
    //     double total_mass;  // total mass of node & any children
    //     Point center_of_mass;   // center of mass for node & any children
    //     void calc_cm();

    //     Point tl;   // top left point of the node's bounds
    //     Point br;   // bottom right point of the node's bounds
        
    //     Node* nw; 
    //     Node* ne; 
    //     Node* sw; 
    //     Node* se; // children nodes
    // };

    template <typename T>
    struct Node
    {
        vector<particle_sys::Body> node_bin;
        Box<T> node_box;
        // children nodes
        Node* nw; 
        Node* ne; 
        Node* sw; 
        Node* se; 
    };

    template <typename T>
    class QuadTree
    {
    public:
        QuadTree();
        void build();
        void insert(particle_sys::Body& j, Node<T>* node);  /* TODO */
        void split(Node<T>* node);                          /* TODO */
        bool is_root() const;                               /* TODO */
        bool in_boundary(Point<T> p) const;
        
    private:
        //static double mass_threshold;
        //static double radius_threshold;
        std::unique_ptr<Node<T>> root;
    };

    // template <typename T>
    // const bool in_boundary(Point<T> p);

    
} // namespace quadtree

#endif