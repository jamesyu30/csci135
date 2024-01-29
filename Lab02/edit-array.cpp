/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2C

printing out one letter at a time
*/

// 
#include <iostream>
using namespace std;


int main(){
    int myData[10];
    int i, v;
    for (int i = 0; i < 10; i++){
        myData[i] = 1;
    }
    do{
        for (int i = 0; i < 10; i++){
            cout << myData[i] << " ";
        }
        cout << endl;
        cout << "Enter an index: ";
        cin >> i;
        cout << "Enter a value: ";
        cin >> v;
        if (i < 10 && i >= 0){
            myData[i] = v;
        }
    }while(i < 10 && i >= 0);
}