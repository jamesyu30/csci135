/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2A

checking valid inputs
*/

// 
#include <iostream>
using namespace std;


int main(){
    int n;
    do{
        cout << "Enter a number between 0 and 100: ";
        cin >> n;
    }while(n <= 0 || n >= 100);
    cout << n*n << endl;
}