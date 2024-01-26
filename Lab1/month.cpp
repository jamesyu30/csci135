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
    int month;
    int year;
    cout << "Enter a year: ";
    cin >> year;
    cout << "Enter a month: ";
    cin >> month;
    if (month == 1 || month ==3 || month==5 || month==7 || month==8 || month==10 || month==12){
        cout << 31 << endl;
    }else if (month != 2){
        cout << 30 << endl;
    }
    else if (year % 4 != 0){
        cout << 28 << endl;
    }else if (year % 100 != 0){
        cout << 29 << endl;
    }else if (year % 400 != 0){
        cout << 28 << endl;
    }else{
        cout << 29 << endl;
    }
}