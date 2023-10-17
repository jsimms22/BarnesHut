#ifndef QUADTREE_H
#define QUADTREE_H

#include "body.h"

struct Point
{
    double x, y;
    Point() { }
    Point(double _x, double _y) 
    :x{_x}, y {_y} { }
};

struct Node
{
    Body b;
    bool filled;
    double total_mass;  // total mass of node & any children
    Point center_of_mass;   // center of mass for node & any children

    Point tl;   // top left point of the node's bounds
    Point br;   // bottom right point of the node's bounds
    
    Node* nw; Node* ne; Node* sw; Node* se; // children nodes
};

class Quad_Tree
{
public:

private:
    static double mass_threshold;
    static double radius_threshold;
    Node* node;

    Quad_Tree() :node{NULL} { }
    void insert(Node* node);
    void quadTreeBuild();
    void split(Node* node)
};

#endif