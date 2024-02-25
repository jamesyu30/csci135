/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6C

vigenere cipher
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

string encryptVigenere(string plaintext, string keyword){
    int c;
    int keywordIndex = 0;
    string cipher =  "";
    for (int i = 0; i < plaintext.length(); i++){
        c = (int)plaintext[i];
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
            cipher += shiftChar(plaintext[i], (int) keyword[keywordIndex % keyword.length()] - 97);
            keywordIndex++;
        }else{
            cipher += plaintext[i];
        }
    }
    return cipher;
}

int main(){
    string text;
    string key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter keyword: ";
    cin >> key;
    cout << "cipher text: " << encryptVigenere(text, key) << endl;
    return 0;
}