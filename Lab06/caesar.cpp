/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6B

caesar cipher - shifts letters to make a code
*/

// 
#include <iostream>
#include <string>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift){
    int cVal = (int) c;
    if (cVal >= 65 && cVal <= 90){
        if (cVal + rshift > 90){
            return (char) (cVal + rshift) % 90 + 64;
        }
        return (char) (cVal + rshift) % 91;
    }else if(cVal >= 97 && cVal <= 122){
        if(cVal + rshift > 122){
            return (char) (((cVal + rshift) % 122) + 96);
        }
        return (char) ((cVal + rshift) % 123);
    }else{
        return (char) c;
    }
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift){
    string cipher = "";
    for (int i = 0; i < plaintext.length(); i++){
        cipher += shiftChar(plaintext[i], rshift);
    }
    return cipher;
}

int main(){
    //cout << shiftChar('a', 5);
    string text;
    int shift;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift: ";
    cin >> shift;
    cout << "cipher text: " << encryptCaesar(text, shift) << endl;
    return 0;
}