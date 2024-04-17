#include <iostream>
#include <vector>
using namespace std;
/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12C

moving elements between vectors
*/
//

void gogeta(vector<int>& goku, vector<int>& vegeta){
    for(int i = 0; i < vegeta.size(); i++){
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}