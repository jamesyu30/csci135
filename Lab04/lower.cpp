/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4D

making a right triangle with asterisks
*/

// 
#include <iostream>
using namespace std;


int main(){
    int s;
    cout << "Enter a length: ";
    cin >> s;

    cout << endl;
    for (int i = 1; i < s+1; i++){
        for (int j = 0; j < i; j++){
            cout << "*";
        }
        cout << endl;
    }
}