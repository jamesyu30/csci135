/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E2.10

Determines cost of gas per 100 miles and how far it can go with the gas in the tank
*/

// 
#include <iostream>
using namespace std;

int main(){
    float gas, mpg, price;
    cout << "Enter amount of gas in the tank: ";
    cin >> gas;
    cout << "Enter miles per gallon: ";
    cin >> mpg;
    cout << "Enter price per gallon: ";
    cin >> price;
    cout << (100/mpg)*price << endl;
    cout << gas*mpg << endl;
}