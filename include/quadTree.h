#ifndef QUADTREE_H
#define QUADTREE_H

#include<array>
#include<memory>
#include "body.h"
#include "point.h"
#include "box.h"

namespace quadtree
{
    struct Node
    {
        std::vector<particle_sys::Body> m_bin;  // particle bodies within this node's "box"
        Box m_box;                              // defined box for node
        std::array<Node*, 4> quad;              // children nodes
        Node* m_parent;                         // parent node

        Node(Box _box, Node* _p) :m_box{_box}, m_parent{_p} 
            { quad = {nullptr,nullptr,nullptr,nullptr}; }

        Node(std::vector<particle_sys::Body> _bin, Box _box, Node* _p) 
            :m_bin{_bin}, m_box{_box}, m_parent{_p} { quad = {nullptr,nullptr,nullptr,nullptr}; }
    };

    void print_node_bin(Node* n);

    class QuadTree
    {
    public:
        QuadTree()
            :m_root{nullptr} { }
        void init_tree(std::vector<particle_sys::Body>& bin, int n);
        void insert(Node* root, particle_sys::Body& b); /* IN PROGRESS */
        //void split(Node* root, std::vector<particle_sys::Body>& bin);

        bool is_root() const { return (m_root->m_parent == nullptr); }
        Node* get_root() const { return m_root; }
        
    private:
        //static double mass_threshold;
        //static double radius_threshold;
        Node* m_root;
    };

    bool in_boundary(Box b, Point p);
    Box create_box(Node* parent, int quad);
} // namespace quadtree

#endif