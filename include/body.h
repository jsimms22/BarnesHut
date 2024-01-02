#ifndef BODY_H
#define BODY_H

#include<cmath>
#include<ctime>
#include<vector>
#include<iostream>
#include<iomanip>
// using std::setprecision;
// using std::setw;
// using std::fixed;

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

namespace particle_sys
{
    class Body
    {
    public:
        Body();
        Body(double _m);
        void move();

        double x;
        double y;
        double m;
        double vx;
        double vy;
        double ax;
        double ay;
        bool is_center = false;
    };

    void init_particles(std::vector<Body>& bin, int num_bodies);
} // namespace particle_sys

#endif