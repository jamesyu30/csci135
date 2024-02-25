/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6A

prints out ascii values of a string
*/

// 
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cout << "Enter a string: ";
    //getline reads input after whitespace
    getline(cin, s);
    for (int i = 0; i < s.length(); i++){
        cout << s[i] << " " << (int) s[i] << endl;
    }
}