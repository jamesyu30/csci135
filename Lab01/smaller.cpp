/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab1A

smaller of two integers
*/

#include <iostream>
using namespace std;

int main(){
    cout << "input two integers: " << endl;
    int i,j;
    cin >> i;
    cin >> j;
    if (i > j){
        cout << j << endl;
    }else{
        cout << i << endl;
    }
}