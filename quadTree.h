#ifndef QUADTREE_H
#define QUADTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "body.h"

using std::vector;

struct Point
{
  double x, y;
  Point() { }
  Point(double _x, double _y) 
    :x{_x}, y {_y} { }
};

class Node
{
public: // for now
  Point pos;
  vector<Body> bin;
  bool filled;
  Node() :filled{false} { }
  Node(Point _pos, vector<Body> _bin) 
    :pos{_pos}, bin{_bin}, filled{true} { }
};

class Quad_Tree
{
  private:
    Point tl; //top left point of the node's bounds
    Point br; //bottom right point of the node's bounds
    
    //contains details of the node
    Node *node_info;
    
    //children of the node
    Quad_Tree *nw; 
    Quad_Tree *ne;
    Quad_Tree *sw;
    Quad_Tree *se;
  
  public:
    Quad_Tree()
    {
      tl = Point(0,0);
      br = Point(0,0);
      node_info = NULL;
      nw = NULL;
      ne = NULL;
      sw = NULL;
      se = NULL;
    }
    Quad_Tree(Point _tl, Point _br)
    {
      tl = _tl;
      br = _br;
      node_info = NULL;
      nw = NULL;
      ne = NULL;
      sw = NULL;
      se = NULL;
  
    }
//    void Insert(Body, Node*);
//    void Quad_Tree_Build();
//    bool inBoundary(Point);
};

#endif