/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 7B

indents based on curly brackets
*/
//
//
//
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int countChar(string line, char c){
    int count = 0;
    for (int i = 0; i < line.length(); i++){
        if (line[i] == c){
            count++;
        }
    }
    return count;
}

void printMultiple(char c, int t){
    for (int i = 0; i < t; i++){
        cout << c;
    }
}

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
//
int main(){
    string code;
    string newCode = "";
    int open = 0;
    int close = 0;
    while (getline(cin, code)){
        // cout << open;
        // cout << close;
        newCode = removeLeadingSpaces(code);
        if (newCode[0] == '}'){
            printMultiple('\t', open - close - 1);
        }else{
            printMultiple('\t', open - close);
        }
        close += countChar(newCode, '}');
        open += countChar(newCode, '{');
        for (int i = 0; i < newCode.length(); i++){
            
            cout << newCode[i];
        }
        cout << endl;

    }
}