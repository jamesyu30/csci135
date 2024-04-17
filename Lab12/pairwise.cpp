#include <iostream>
#include <vector>
using namespace std;
/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12A

using vectors
*/
//

vector<int> sumPairWise(vector<int>& v1, vector<int>& v2){
    int shorter; //shorter length
    int longer; //longer length
    vector<int> sum;
    if (v1.size() > v2.size()){
        shorter = v2.size();
        longer = v1.size();

        for(int i = 0; i < shorter; i++){
            sum.push_back(v1[i]+v2[i]);
        }
        for (int i = 0; i < longer-shorter; i++){
            sum.push_back(v1[i+shorter]);
        }
    }else if (v1.size() < v2.size()){
        shorter = v1.size();
        longer = v2.size();

        for(int i = 0; i < shorter; i++){
            sum.push_back(v1[i]+v2[i]);
        }
        for (int i = 0; i < longer-shorter; i++){
            sum.push_back(v2[i+shorter]);
        }
    }else{
        shorter = v1.size();
        longer = v2.size();

        for(int i = 0; i < shorter; i++){
            sum.push_back(v1[i]+v2[i]);
        }
    }
    return sum;
}