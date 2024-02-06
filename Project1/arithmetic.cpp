
// Author: James Yu
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1A

// making a simple math problem using rand


// 
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


int main(){
    char op[5] = {'+', '-', '*', '/', '%'};

    char randop = op[rand() % 5]; // selects random operator
    int first = rand() % 10; //generates number from 0 to 9
    int second = rand() % 10;

    //checks if second number is 0
    do{
        second = rand() % 10 + 1;
    }
    while((randop == '/' || randop == '%') && second == 0);

    float ans;
    //does the operation
    if (randop == '+'){
        ans = first + second;
    }
    if (randop == '-'){
        ans = first - second;
    }
    if (randop == '*'){
        ans = first * second;
    }
    if (randop == '/'){
        ans = first / second;
    }
    if (randop == '%'){
        ans = first % second;
    }

    float inAns;
    // asks user for answer and checks it
    cout << "what is " << first << " " << randop << " " << second << "?" << endl;
    cin >> inAns;
    cout << boolalpha << (inAns == ans);    
}