/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2B

printing integers from an interval
*/

// 
#include <iostream>
using namespace std;


int main(){
    int l, u;
    cout << "Enter l: ";
    cin >> l;
    cout << "Enter u: ";
    cin >> u;
    for (int i = l; i < u; i++){
        cout << i << endl;
    }
}