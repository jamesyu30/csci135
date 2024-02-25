/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.14

sorting two values (bubble sort)
*/

// 

#include <iostream>
#include <string>
using namespace std;

void sort2(int& a, int& b){
    int placeholder = a;
    if (a > b){
        a = b;
        b = placeholder;
    }
}

int main(){
    int a = 1;
    int b = 4;

    sort2(a, b);
    cout << a << " " << b << endl;

    int c = 5;
    int d = 4;

    sort2(c, d);
    cout << c << " " << d << endl;
    return 0;
}
