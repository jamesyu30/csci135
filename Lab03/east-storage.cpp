/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3A

reading a file with the date as input, outputting the east basin storage
*/

// 
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iostream>
using namespace std;


int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file

    string d;
    cout << "Enter a date: ";
    cin >> d;

    string date;
    float eastSt; 
    while(fin >> date >> eastSt) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        if (d == date){
            cout << eastSt << endl;
        }
    
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 
    }
    fin.close();
}