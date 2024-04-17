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

vector<int> makeVector(int n){
    vector<int> a;
    for (int i = 0; i < n; i++){
        a.push_back(i);
    }
    return a;
}

int main(){
    return 0;
}
