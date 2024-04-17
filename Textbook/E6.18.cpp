/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E6.18

combining vectors
*/

// 

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b){
    vector<int> total;
    for (int i = 0; i < a.size(); i++){
        total.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++){
        total.push_back(b[i]);
    }
    return total;
}