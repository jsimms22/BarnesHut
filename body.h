#ifndef BODY_H
#define BODY_H

#include<cmath>
#include<ctime>

extern const double _PI;
extern const double _G;
extern const double _pMaxMass;
extern const double _pMinMass;
extern const double _pWidth;
extern const double _pHeight;
extern const double _pMaxDist;
extern const double _pMinDist;
extern const double _GCM;
extern const double _dt;

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
    
    Body();
    Body(double _m);
    void Move();
};

#endif