/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E4.8

printing out one letter at a time
*/

// 
#include <iostream>
using namespace std;


int main(){
    string n;
    cout << "Enter a name: ";
    cin >> n;
    for (int i = 0; i < n.length(); i++){
        cout << n[i] << endl;
    }
}