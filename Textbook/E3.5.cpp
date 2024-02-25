/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E3.5

increasing, decreasing, or neither in a series of three numbers
*/

// 
#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a < b && b < c){
        cout << "increasing";
    }else if (c < b and b < a){
        cout << "decreasing";
    }else{
        cout << "neither";
    }
}