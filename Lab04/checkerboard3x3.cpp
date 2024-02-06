/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4G

making a 3x3 checkerboard with asterisks
*/

// 
#include <iostream>
using namespace std;


int main(){
    int h, w;

    cout << "Enter width: ";
    cin >> w;

    cout << "Enter height: ";
    cin >> h;

    cout << "Shape: " << endl;
    for (int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if (i % 6 < 3){
                if (j % 6 < 3){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            else{
                if (j % 6 < 3){
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