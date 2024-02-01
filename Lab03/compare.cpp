/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3C

Finding if the east or west basin is greater
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
    bool interval = false; 
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration
        if (date == d){
            interval = true;
        }
        if (interval){
            if (eastEl == westEl){
                cout << date << " Equal" << endl;
            }else if (eastEl > westEl){
                cout << date << " East" << endl;
            }else{
                cout << date << " West" << endl;
            }
            
        }

        if (date == d2){
            interval = false;
        }

        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns
    }
    fin.close(); 
    }