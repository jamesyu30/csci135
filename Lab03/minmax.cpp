/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3B

finding the min/max in east basin storage
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

    string date;
    float eastSt;

    float min = 59.94;
    float max = 0; 
    while(fin >> date >> eastSt) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        if (eastSt < min){
            min = eastSt;
        }
        if (eastSt > max){
            max =  eastSt;
        }
    
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 
    }
    fin.close();

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
}