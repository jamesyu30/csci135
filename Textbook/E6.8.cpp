/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E6.8

checking if arrays are equal
*/

// 

#include <iostream>
#include <string>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size){
    if (a_size != b_size){
        return false;
    }
    for (int i = 0; i < b_size; i++){
            if (a[i] != b [i]){
                return false;
        }
    }
    return true;
}


int main(){
    return 0;
}