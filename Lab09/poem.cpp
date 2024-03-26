/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9D

deleting memory
*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point
        //deletes memory of p
        delete p;
    }
}