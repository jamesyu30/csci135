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

bool generateProb(int i){
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
    cout << "(" << i << ") " << "what is " << first << " " << randop << " " << second << "?" << " ";
    cin >> inAns;
    cout << boolalpha << (inAns == ans) << endl << endl;   
    return (inAns == ans);
}

int main(){
    float right = 0;
    int num = 0;

    cout << "Enter the total number of questions to ask: ";
    cin >> num;
    
    while(num < 1){
        cout << "The number of questions cannot be zero or negative. Re-enter: ";
        cin >> num;
    }
    for (int i = 0; i < num; i++){
        if(generateProb(i+1)){
            right++;
        }
    }

    float percent = right/num;
    cout << "percentage correct: " << percent*100 << "%" << endl;

    if (percent >= .89999){
        cout << "letter grade: A" << endl;
    }
    else if (percent >= .7999){
        cout << "letter grade: B" << endl;
    }
    else if (percent >= .69999){
        cout << "letter grade: C" << endl;
    }
    else if (percent >= .59999){
        cout << "letter grade: D" << endl;
    }
    else{
        cout << "letter grade: F" << endl;
    }
}
