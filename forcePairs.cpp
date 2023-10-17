#include<cstdlib>
#include<string>
#include<iostream>
#include<vector>
using std::vector;
#include<iomanip>
using std::setprecision;
using std::setw;
using std::fixed;
#include<cmath>
#include "body.h"
 
const double _PI = atan(1.0);
const double _G = 0.1;
const double _pMaxMass = 2.0;
const double _pMinMass = 1.0;
const double _pWidth = 327680.0;
const double _pHeight = 327680.0;
const double _pMaxDist = 20000.0;
const double _pMinDist = 50.0;
const double _GCM = 1000000.0;
const double _dt = .1;

void Init_Particles(vector<Body>& bin, int num_bodies)
// generating bodies
{
    // populating bodies with initial values
    for (int i = 0; i < num_bodies; i++) { bin.push_back(Body()); }
    // adding the center body
    bin.push_back(Body(_GCM));
    std::cout << "all bodies initialized, total count in the bin: " << bin.size() << '\n';
}

void Accel(Body &body, Body &neighbor)
// calculating Gravitational acceleration vector 
// acceleration of a body = (Grav_Constant * neighbor of mass / radius^3) * unit_vector
{
    double dx = neighbor.x - body.x;
    double dy = neighbor.y - body.y;
    double radius = sqrt(dx*dx + dy*dy);
    body.ax += ((_G * neighbor.m) / pow(radius,3)) * dx;
    body.ay += ((_G * neighbor.m) / pow(radius,3)) * dy;
}



void Loop(vector<Body>& bin) {
    for (int i = 0; i < bin.size(); i++) {
        bin[i].ax = bin[i].ay = 0.0;
        for (int j = 0; j < bin.size(); j++) {
            if (i != j) { Accel(bin[i],bin[j]); }
        }
    }
    
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i].is_center == true) {
            bin[i].vx = bin[i].vy = 0.0;
            bin[i].x = bin[i].y = 0.0;
            std::cout << "center body reset\n";
        } else {
            bin[i].Move();
            std::cout << "body " << i << " moved\n"; 
        }
    }
}

int main()
{
    int n = 5;
    double totalTime = 0, maxTime = _dt*3;
    vector<Body> body_bin;

    Init_Particles(body_bin,n);

    do {
        Loop(body_bin);
        totalTime += _dt;
    } while(totalTime <= maxTime);
}
