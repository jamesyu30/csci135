/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4E

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
    for (int i = s; i > 0; i--){
        for (int j = 0; j < s-i; j++){
            cout << " ";
        }
        for (int k = 0; k < i; k++){
            cout << "*";
        }
        cout << endl;
    }
}