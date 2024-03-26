/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.16

using structs
*/

// 

#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double x;
    double y;
};

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main(){
    return 0;
}