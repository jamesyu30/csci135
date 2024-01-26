/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1C

determines if a year is a leap year
*/

// 
#include <iostream>
using namespace std;

int main(){
    int year;
    cout << "Enter a year: ";
    cin >> year; 
    if (year % 4 != 0){
        cout << "Common year" << endl;
    }else if (year % 100 != 0){
        cout << "leap year" << endl;
    }else if (year % 400 != 0){
        cout << "common year" << endl;
    }else{
        cout << "Leap year" << endl;
    }
}