#ifndef BODY_H
#define BODY_H

class Body
{
public:
  double x;
  double y;
  double m;
  double vx;
  double vy;
  double ax;
  double ay;
  bool is_center = false;
    
  Body() { }
  Body(double _m) 
    :x{0.0}, y{0.0}, m{_m}, vx{0.0}, vy{0.0}, ax{0.0}, ay{0.0}, is_center{true} { }
  Body(double _x, double _y, double _m,double _vx, double _vy, double _ax, double _ay)
    :x(_x), y{_y}, m{_m}, vx{_vx}, vy{vy}, ax{_ax}, ay{_ay} { }
};

#endif