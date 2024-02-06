/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4C

making a cross of asterisks
*/

// 
#include <iostream>
using namespace std;


int main(){
    int s;
    cout << "Enter size: ";
    cin >> s;

    cout << endl;
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            if (j == s - 1 - i || j == i){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}