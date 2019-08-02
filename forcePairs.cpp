#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
using std::vector;
#include <iomanip>
using std::setprecision;
using std::setw;
using std::fixed;
#include <math.h>
#include <float.h>
#include <time.h>
#include <sys/time.h>
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

//
// generating bodies
//
void Init_Particles( int n, body_t* pBody)
{
  srand48(time(0));
  int i = 0;
  for (; i < n; i++) {
    double angle = static_cast <double> (rand()) 
  	/ (static_cast <double> (RAND_MAX 
	/ (2.0 * static_cast <double> (_PI))));
    double coef = static_cast <double> (rand()) 
	/ static_cast <double> (RAND_MAX);
    double dist = _pMinDist + ((_pMaxDist - _pMinDist) * (coef * coef));
    
    double posx = cos(angle) * dist + (_pWidth / 2.0);
    double posy = sin(angle) * dist + (_pHeight / 2.0);

    double orbVel = sqrt((_GCM * static_cast <double> (_G)) 
	/ dist);
    double velx = (sin(angle) * orbVel);
    double vely = (-1.0*cos(angle) * orbVel);
    
    double mass = _pMinMass + static_cast <double> (rand() % static_cast
	<int> (_pMaxMass - _pMinMass));
    
    // populating with bodies
    pBody[i].x = posx;
    pBody[i].y = posy;
    pBody[i].m = mass;
    pBody[i].vx = velx;
    pBody[i].vy = vely;
    pBody[i].ax = 0.0;
    pBody[i].ay = 0.0;
  }
  // adding the center body
  pBody[i+1].x = 0.0;
  pBody[i+1].y = 0.0;
  pBody[i+1].m = _GCM;
  pBody[i+1].vx = 0.0;
  pBody[i+1].vy = 0.0;
  pBody[i+1].ax = 0.0;
  pBody[i+1].ay = 0.0;
}

//
// calculating forces
//
void Force(body_t &body, body_t &neighbor)
{
  double dx = neighbor.x - body.x;
  double dy = neighbor.y - body.y;
  double radius = sqrt(dx*dx + dy*dy);
  body.ax += ((_G * neighbor.m) / pow(radius,3)) * dx;
  body.ay += ((_G * neighbor.m) / pow(radius,3)) * dy;
  
}

//
// moving bodies
//
void Move(body_t &body)
{
  body.vx += body.ax * _dt;
  body.vy += body.ay * _dt;
  body.x += body.vx * _dt;
  body.y += body.vy * _dt;
}
int main()
{
  int n = 500;
  double totalTime = 0, maxTime = _dt*500;
  body_t *body = (body_t*) malloc( (n+1) * sizeof(body_t) );

  Init_Particles(n,body);
  n++;

  do
  {
    for (int i = 0; i < n; i++) 
    {
      body[i].ax = body[i].ay = 0.0;
      for (int j = 0; j < n; j++) 
      {
        if (i != j) 
        {
	  Force(body[i],body[j]);
        }
      }
    }
   
    for (int i = 0; i < n; i++) 
    {
	printf("%d",i);
      Move(body[i]);
    }

    body[n-1].vx = body[n-1].vy = 0.0;
    body[n-1].x = body[n-1].y = 0.0;
    
    totalTime += _dt;
  } while(totalTime < maxTime);
   

  free(body);
}
