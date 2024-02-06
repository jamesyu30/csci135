/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4B

making a checkerboard of asterisks using a 2d array
*/

// 
#include <iostream>
using namespace std;


int main(){
    int h,w;
    cout << "Enter width: ";
    cin >> w;
    cout << "Enter height: ";
    cin >> h;


    cout << endl << "Shape: " << endl;;
    for (int r = 0; r < h; r++){
        for (int i = 0; i < w; i++){
            if (r % 2 == 0){
                if (i % 2 == 0){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            else{
                if (i % 2 == 0){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
            }
        }
        cout << endl;
    }
}