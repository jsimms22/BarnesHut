#ifndef FORCE_H
#define FORCE_H

#include<vector>
using std::vector;
#include<cmath>
#include "body.h"

extern const double _G;

namespace particle_sys
{
    void accel(Body &body, Body &neighbor)
    // calculating Gravitational acceleration vector 
    // acceleration of a body = (Grav_Constant * neighbor of mass / radius^3) * unit_vector
    {
        double dx = neighbor.x - body.x;
        double dy = neighbor.y - body.y;
        double radius = sqrt(dx*dx + dy*dy);
        body.ax += ((_G * neighbor.m) / pow(radius,3)) * dx;
        body.ay += ((_G * neighbor.m) / pow(radius,3)) * dy;
    }
}

#endif