#include<cstdlib>
#include<string>
#include<iostream>
#include<vector>
// #include<iomanip>
// using std::setprecision;
// using std::setw;
// using std::fixed;
#include<cmath>
#include "../include/body.h"
#include "../include/force.h"
#include "../include/quadTree.h"
 
const double _PI = atan(1.0);
constexpr double _G = 0.1;
constexpr double _pMaxMass = 2.0;
constexpr double _pMinMass = 1.0;
constexpr double _pWidth = 327680.0;
constexpr double _pHeight = 327680.0;
constexpr double _pMaxDist = 20000.0;
constexpr double _pMinDist = 50.0;
constexpr double _GCM = 1000000.0;
constexpr double _dt = .1;

void Loop(vector<particle_sys::Body>& bin) {
    for (int i = 0; i < bin.size(); i++) {
        bin[i].ax = bin[i].ay = 0.0;
        for (int j = 0; j < bin.size(); j++) {
            if (i != j) { particle_sys::accel(bin[i],bin[j]); }
        }
    }
    
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i].is_center == true) {
            bin[i].vx = bin[i].vy = 0.0;
            bin[i].x = bin[i].y = 0.0;
            std::cout << "center body reset\n";
        } else {
            bin[i].move();
            std::cout << "body " << i << " moved\n"; 
        }
    }
}

int main()
{
    srand(time(NULL));
    int n = 5;
    double totalTime = 0, maxTime = _dt*3;
    std::vector<particle_sys::Body> body_bin;

    //particle_sys::init_particles(body_bin,n);
    quadtree::QuadTree qt = quadtree::QuadTree();
    qt.init_tree(body_bin,n);

    quadtree::print_node_bin(qt.get_root());

    // do {
    //     Loop(body_bin);
    //     totalTime += _dt;
    // } while(totalTime <= maxTime);
}
