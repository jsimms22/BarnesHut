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
#include<ctime>
#include "body.h"
 
#define _PI 3.14159265
#define _G 0.1
#define _pMaxMass 2
#define _pMinMass 1
#define _pWidth 327680
#define _pHeight 327680
#define _pMaxDist 20000
#define _pMinDist 50
#define _GCM 1000000
#define _dt .1

void Init_Particles(vector<Body>& bin, int num_bodies)
// generating bodies
{
  srand(time(0));
  // populating bodies with initial values
  for (int i = 0; i < num_bodies; i++) {
    double angle = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (2.0 * static_cast<double>(_PI))));
    double coef = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    double dist = _pMinDist + ((_pMaxDist - _pMinDist) * (coef * coef));
    
    double posx = cos(angle) * dist + (_pWidth / 2.0);
    double posy = sin(angle) * dist + (_pHeight / 2.0);

    double orbVel = sqrt((_GCM * static_cast<double>(_G)) / dist);
    double velx = (sin(angle) * orbVel);
    double vely = (-1.0 * cos(angle) * orbVel);
    
    double mass = _pMinMass + static_cast <double> (rand() % static_cast<int> (_pMaxMass - _pMinMass));
    
    bin.push_back(Body(posx,posy,mass,velx,vely,0.0,0.0));
  }
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

void Move(Body &body)
// moving bodies
{
  body.vx += body.ax * _dt;
  body.vy += body.ay * _dt;
  body.x += body.vx * _dt;
  body.y += body.vy * _dt;
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
      Move(bin[i]);
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
