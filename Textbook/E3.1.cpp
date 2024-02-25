/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E3.1

positve, negative, or 0
*/

// 
#include <iostream>
using namespace std;

int main(){
    int i;
    cout << "Enter a number: ";
    cin >> i;
    if (i>0){
        cout << "positive" << endl;
    }else if (i<0){
        cout << "negative" << endl;
    }else{
        cout << "zero" << endl;
    }
}