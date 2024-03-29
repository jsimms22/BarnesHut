#include "../include/body.h"

namespace particle_sys
{
    Body::Body()
    {
        double angle = (static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX)) * (2.0 * _PI);
        double dist = (((static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX))) * _pMaxDist) + (_pMinDist);

        x = cos(angle) * dist;
        y = sin(angle) * dist;

        double orbVel = sqrt((_GCM * static_cast<double>(_G)) / dist);
        vx = (sin(angle) * orbVel);
        vy = (-1.0 * cos(angle) * orbVel);
        
        m = _pMinMass + static_cast <double> (rand() % static_cast<int> (_pMaxMass - _pMinMass));
        is_center = false;
    }

    Body::Body(double _m) 
        :x{_pWidth/2.0}, y{_pHeight/2.0}, m{_m}, vx{0.0}, vy{0.0}, ax{0.0}, ay{0.0}, is_center{true} { }

    void Body::move()
    // moving bodies
    {
        vx += ax * _dt;
        vy += ay * _dt;
        x += vx * _dt;
        y += vy * _dt;
    }

    void init_particles(std::vector<Body>& bin, int num_bodies)
    // generating bodies
    {
        // populating bodies with initial values
        for (int i = 0; i < num_bodies; i++) { bin.push_back(Body()); }
        // adding the center body
        bin.push_back(Body(_GCM));
        std::cout << "all bodies initialized, total count in the bin: " << bin.size() << '\n';
    }  
} // namespace particle_sys


