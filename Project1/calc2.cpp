// Author: James Yu
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1C

// reading a csv file and using it to ask questions
// 
#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("test.csv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    string ans;
    float input;
    float count = 0;
    float right = 0;
    string line;
    // get line reads from fin and assigns it to var line
    while(getline(fin, line)) { 
        // this loop reads the file line-by-line
        //cout << line.substr(0, line.find(",")); QUESTION
        //cout << line.substr(line.find(",")+1, line.size()); ANSWER
        //cout << "LINE: " << line << endl;
        ans = (string) line.substr(line.find(",")+1, line.size());
        cout << "(" << count+1 << ") " << "what is " << line.substr(0, line.find(",")) << "? ";
        cin >> input;
        // if its right add 1 to right counter
        if(input == stof(ans)){
            right++;
        }

        //checks if its right or not
        cout << boolalpha << (input == stof(ans)) << endl << endl;
        //question number
        count++;
        //fin.ignore makes it skip every other line = bad
        //fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 
    }
    fin.close();

    float percent = right/count;
    cout << "percentage correct: " << percent*100 << "%" << endl;

     if (percent >= .8999999){
        cout << "letter grade: A" << endl;
    }
    else if (percent >= .799999){
        cout << "letter grade: B" << endl;
    }
    else if (percent >= .699999){
        cout << "letter grade: C" << endl;
    }
    else if (percent >= .5999999){
        cout << "letter grade: D" << endl;
    }
    else{
        cout << "letter grade: F" << endl;
    }
}