/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1B

smaller of three integers
*/

// 
#include <iostream>
using namespace std;

int main(){
    cout << "input three integers: " << endl;
    int i,j,k;
    cin >> i;
    cin >> j;
    cin >> k;
    if (i > j){
        if (j > k){
            cout << k << endl;
        }else{
            cout << j << endl;
        }
    }else{
        if (i > k){
            cout << k << endl;
        }else{
            cout << i << endl;
        }
    }
}