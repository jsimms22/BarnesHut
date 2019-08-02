#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "body.h"

using std::vector;

struct Point
{
  double x;
  double y;
  Point(double _x, double _y) { x = _x; y = _y; }
  Point() { }
};

struct Node
{
  Point pos;
  Body b;
  bool fill;

  Node(Point _pos, Body _body) 
  { 
    pos = _pos; 
    b = _body;
    fill = 1;
  }
  Node() { fill = 0; }
};

class Quad_Tree
{
  private:
    Point tl; //top left point of the node's bounds
    Point br; //bottom right point of the node's bounds
    
    //contains details of the node
    Node *n;
    
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
      n = NULL;
      nw = NULL;
      ne = NULL;
      sw = NULL;
      se = NULL;
    }
    Quad_Tree(Point _tl, Point _br)
    {
      n = NULL;
      nw = NULL;
      ne = NULL;
      sw = NULL;
      se = NULL;
      tl = _tl;
      br = _br;
    }
//    void Insert(Body, Node*);
//    void Quad_Tree_Build();
//    bool inBoundary(Point);
};

/*bool Quad_Tree::inBoundary(Point p) 
{
  return (p.x >= tl.x &&
	p.x <= br.x &&
	p.y >= tl.y &&
	p.y <= br.y);
}

void Quad_Tree::Insert(Body j, Node* n)
{
  if (n == NULL) return;
  
  //current quad cannot contain it
  if(!inBoundary(n->pos)) return;  
}*/

