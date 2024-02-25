/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.6

finding the middle of the string
*/

// 
#include <iostream>
#include <string>
using namespace std;

string middle (string str){
    if (str.length() % 2 == 0){
        return str.substr((str.length() / 2) - 1, 2);
    }
    else{
        return str.substr((str.length() / 2), 1);
    }
}

int main(){
    return 0;
}