/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3C

outputting west basin elevation in reverse order (in dates)
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
    cout << "Enter starting date: ";
    cin >> d;

    string d2;
    cout << "Enter ending date: ";
    cin >> d2;

    string date;
    float eastSt;
    float eastEl;
    float westSt;
    float westEl;
    string dArr[365];
    float ElArr[365];
    int i = 0;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration
        dArr[i] = date;
        ElArr[i] = westEl;
        i++;
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns
    }
    bool interval = false;
    for (int j = (sizeof(dArr)/sizeof(dArr[0]))-1; j >= 0; j--){
        if (dArr[j] == d2){
            interval = true;
        }
        if (interval)
        {
            cout << dArr[j] << "\t" << ElArr[j] << " ft" << endl;
        }
        if (dArr[j] == d){
            interval = false;
        }
        
    }
    fin.close(); 
    }