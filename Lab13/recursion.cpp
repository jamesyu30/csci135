/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 13A

recursion to print out numbers in a range
adding numbers in a range
checking if a string is alnum
*/
//
//
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void printRange(int left, int right){
    if (left <= right){
        cout << left << " ";
        printRange(left+1, right);
    }
}

int sumRange(int left, int right){
    if (left <= right){
        return left+sumRange(left+1, right);
    }
    return 0;
}

int sumArrayInRange(int *arr, int left, int right){
    if (left <= right){
        return arr[left]+sumArrayInRange(arr, left+1, right);
    }
    return 0;
}

int sumArray(int* arr, int size){
    return sumArrayInRange(arr, 0, size-1);
}

bool isAlphanumeric(string s){
    if(s == ""){
        return true;
    }else{
        return isalnum(s[0]) && isAlphanumeric(s.substr(1));
    }
}

int main(){
    //printRange(-2, 10);
    cout << sumRange(1, 10) << endl;

    int a[] = {1, 2, 3, 4};
    cout << sumArray(a, 4) << endl;
    return 0;
}
