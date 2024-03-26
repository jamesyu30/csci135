/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.18

using structs to compute triangle perimeter
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

struct Triangle{
    Point a;
    Point b;
    Point c;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double perimeter(Triangle t) {
    double sideAB = distance(t.a, t.b);
    double sideBC = distance(t.b, t.c);
    double sideCA = distance(t.c, t.a);
    return sideAB + sideBC + sideCA;
}

int main(){
    return 0;
}