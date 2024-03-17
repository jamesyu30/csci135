/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.1

sorting two pointers
*/

// 

#include <iostream>
using namespace std;

void sort2(double* p, double* q){
    //cout << p; prints out address
    //cout << *p; prints out acutal value
    if (*p > *q){
        double temp = *p;
        *p = *q;
        *q = temp;
    }
}

int main(){
    double x = 7;
    double y = 3;
    //& changes var to its address
    sort2(&x, &y);
    cout << x << " " << y;
    return 0;
}