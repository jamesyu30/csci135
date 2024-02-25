/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6C

decrypting the caesar and vigenere ciphers
*/

// 
#include <iostream>
#include <string>
using namespace std;

char shiftCharR(char c, int rshift){
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
        cipher += shiftCharR(plaintext[i], rshift);
    }
    return cipher;
}

string encryptVigenere(string plaintext, string keyword){
    int c;
    int keywordIndex = 0;
    string cipher =  "";
    for (int i = 0; i < plaintext.length(); i++){
        c = (int)plaintext[i];
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
            cipher += shiftCharR(plaintext[i], (int) keyword[keywordIndex % keyword.length()] - 97);
            keywordIndex++;
        }else{
            cipher += plaintext[i];
        }
    }
    return cipher;
}

char shiftCharL(char c, int rshift){
    int cVal = (int) c;
    if (cVal >= 65 && cVal <= 90){
        if (cVal - rshift < 65){
            return (char) (90 - (rshift - (cVal - 64)));
        }
        return (char) (cVal - rshift);
    }else if(cVal >= 97 && cVal <= 122){
        if(cVal - rshift < 97){
            return (char) (122 - (rshift - (cVal - 96)));
        }
        return (char) (cVal - rshift);
    }else{
        return (char) c;
    }
}


string decryptCaesar(string ciphertext, int rshift){
    string original = "";
    for (int i = 0; i < ciphertext.length(); i++){
        original += shiftCharL(ciphertext[i], rshift);
    }
    return original;
}

string decryptVigenere(string ciphertext, string keyword){
    string original = "";
    int c, keywordIndex = 0;
    for (int i = 0; i < ciphertext.length(); i++){
        c = (int)ciphertext[i];
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
            original += shiftCharL(ciphertext[i], (int) keyword[keywordIndex % keyword.length()] - 97);
            keywordIndex++;
        }else{
            original += ciphertext[i];
        }
    }
    return original;
}

int main(){
    //cout << decryptCaesar("R", 10) << endl;
    //cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << endl;
    string text;
    int shift;
    string keyword;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift: ";
    cin >> shift;
    cout << "cipher text: " << encryptCaesar(text, shift) << endl;
    cout << "decrypted: " << decryptCaesar(encryptCaesar(text, shift), shift) << endl;

    cout << "Enter keyword: ";
    cin >> keyword;
    cout << "cipher text: " << encryptVigenere(text, keyword) << endl;
    cout << "decrypted: " << decryptVigenere(encryptVigenere(text, keyword), keyword) << endl;

    return 0;
}