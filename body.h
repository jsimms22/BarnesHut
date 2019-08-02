#ifndef BODY_H
#define BODY_H

typedef struct
{
//public:
  double x;
  double y;
  double m;
  double vx;
  double vy;
  double ax;
  double ay;
    
  /*Body() 
  { 
    x = 0; 
    y = 0;
    m = 0; 
    vx = 0;
    vy = 0;
    ax = 0; 
    ay = 0; 
  }
  Body(double _x, double _y, double _m,double _vx, 
	double _vy, double _ax, double _ay)
  {
    x = _x; 
    y = _y;
    m = _m;;
    vx = _vx;
    vy = _vy; 
    ax = _ax; 
    ay = _ay; 
  }*/
} body_t;
#endif
