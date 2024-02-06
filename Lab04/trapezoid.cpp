/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4F

making a trapezoid with asterisks
*/

// 
#include <iostream>
using namespace std;


int main(){
    int w, h;
    int spaces = 0;
    cout << "Enter width: ";
    cin >> w;
    cout << "Enter height: ";
    cin >> h;

    if ((h*2 > w) && w % 2 == 0){
        cout << "Impossible shape!";
    }
    else if((h*2)-1 > w && (w % 2 != 0)){
        cout << "Impossible shape!";
    }
    else{
        cout << "Shape: " << endl;

        for(int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if (j < spaces || j > w - 1 - spaces){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
            }
            spaces += 1;
            cout << endl;
        }
    }
}