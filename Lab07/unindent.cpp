/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 7A

deletes whitespace before text
*/

// 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line) {
    string newLine = "";
    bool space = true;
    for (int i = 0; i < line.length(); i++){
        if (!isspace(line[i])){
            space = false;
        }
        if (!space){
            newLine += line[i];
        }
    }
    return newLine;
}

int main(){
    //cout << removeLeadingSpaces("       int x = 1;  ");
    string code;
    //cout << "Enter code: ";
    //cin >> code;
    while (getline(cin, code))
    cout << removeLeadingSpaces(code) << endl;
}