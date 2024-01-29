/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2D

fibonacci numbers using an array
*/

// 
#include <iostream>
using namespace std;


int main(){
    int fib[60];
    fib[0] = 0;
    fib [1] = 1;
    cout << fib[0] << endl << fib[1] << endl;
    for (int i = 2; i < 60; i++){
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << endl;
    }
}