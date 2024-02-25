/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.15

sorting three values (bubble sort)
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

void sort3(int& a, int& b, int& c){
    sort2(a, b);
    sort2(a, c);
    sort2(b, c);
}

int main(){
    int a = 1;
    int b = 5;
    int c = 3;
    sort3(a, b, c);
    cout << a << " " << b << " " << c << " " << endl;
    return 0;
}