// Author: James Yu
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1B

// generating multiple problems using rand and grading it


// 
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    float right = 0;
    int num = 0;
    char op[5] = {'+', '-', '*', '/', '%'};
    char randop;
    float first, second;

    cout << "Enter the total number of questions to ask: ";
    cin >> num;
    
    while(num < 1){
        cout << "The number of questions cannot be zero or negative. Re-enter: ";
        cin >> num;
    }
    for (int i = 0; i < num; i++){

        randop = op[rand() % 5]; // selects random operator
        first = rand() % 10; //generates number from 0 to 9

        //checks if second number is 0
        if (randop == '/' || randop == '%'){
            second = rand() % 9 + 1;
        }else{
            second = rand() % 10;
        }

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
            ans = (int) first % (int) second;
        }

        float inAns;
        // asks user for answer and checks it
        cout << "(" << i+1 << ") " << "what is " << first << " " << randop << " " << second << "?" << " ";
        cin >> inAns;
        if (inAns == ans){
            right++;
        }
        cout << boolalpha << (inAns == ans) << endl;   

    }

    float percent = right * 100 /num;

    cout << "percentage correct: " << percent << "%" << endl;
    cout << "letter grade: ";

    if (percent/100 >= .8999999){
        cout << "A";
    }
    else if (percent/100 >= .799999){
        cout << "B";
    }
    else if (percent/100 >= .699999){
        cout << "C";
    }
    else if (percent/100 >= .5999999){
        cout << "D";
    }
    else{
        cout << "F";
    }
    cout << endl;
}
