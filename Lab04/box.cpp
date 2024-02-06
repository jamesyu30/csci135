/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4A

making a box of asterisks using a 2d array
*/

// 
#include <iostream>
using namespace std;


int main(){
    int h,w;
    cout << "Enter height: ";
    cin >> h;
    cout << "Enter width: ";
    cin >> w;

    cout << "Shape: " << endl;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cout << "*";
        }
        cout << endl;
    }
}