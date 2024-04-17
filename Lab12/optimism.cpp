#include <iostream>
#include <vector>
using namespace std;
/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12B

filtering negative numbers in vectors
*/
//
vector<int> goodVibes(const vector<int> v){
    vector<int> newV;
    for (int i = 0; i < v.size(); i++){
        if (v[i] > 0){
            newV.push_back(v[i]);
        }
    }
    return newV;
}