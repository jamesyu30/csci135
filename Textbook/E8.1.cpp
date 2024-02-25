/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E8.1

editing and reading a file
*/

// 
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iostream>
using namespace std;


int main(){
    ofstream fout; 
    fout.open("hello.txt");

    if (fout.fail()) {
        cerr << "File cannot be opened for writing." << endl;
        exit(1); // exit if failed to open the file
    }

    fout << "Hello, World!";
    fout.close();

    ifstream fin; 
    fin.open("hello.txt");

    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    string out;
    getline(fin, out);
    cout << out;

    fin.close();
}