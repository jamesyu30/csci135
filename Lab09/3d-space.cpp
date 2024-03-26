/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9A

distance from origin to a point
*/
//
#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;

};

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *point = new Coord3D;
    
    point->x = x;
    point->y = y;
    point->z = z;
    
    return point;
}

// free memory
void deleteCoord3D(Coord3D *p){
    delete p;
}

double length(Coord3D *p){
    return sqrt( pow(abs(p->x), 2) + pow(abs(p->y), 2) + pow(abs(p->z), 2)); 
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    if(length(p1) < length(p2)){
        return p2;
    }
    return p1;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    ppos->x = ppos->x + pvel->x * dt;
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;
}

int main() {
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
}