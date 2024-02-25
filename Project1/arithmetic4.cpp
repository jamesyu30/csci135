// Author: James Yu
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1D

// randonly getting questions from csv file


// 
#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <fstream>
using namespace std;

int main(){
    string qArray[20]; //array of all questionss
    double ansArray[20]; //array of answers
    string line, ans;
    int index = 0, right = 0; //index of the arrays to initialize them, the number of questions right
    int size, randnum;
    double correct = 0; //percentage correct
    int q = 1; //question number
    double input; //user input/answer


    ifstream fin("test.csv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    while(getline(fin, line, ',') && getline(fin, ans)){
        qArray[index] = line;
        ansArray[index] = stof(ans);
        index++;
    }

    size = index;

    while (size > 0 && correct < .6){
        randnum = rand() % size;
        cout << "(" << q << ") what is " << qArray[randnum] << "? ";
        cin >> input;

        //cout << input << endl;
        cout << boolalpha << (input == ansArray[randnum]) << endl << endl;
        if (input == ansArray[randnum]){
            right++;
            correct = (double) right/index;
        }
        //cout << correct << endl;

        q++; //increment question number

        swap(qArray[randnum], qArray[size-1]);
        swap(ansArray[randnum], ansArray[size-1]);

        //checks if arrays are being swapped properly
        // for (int i = 0; i < 10; i++){
        //     cout << "Question: " << qArray[i] << '\t' << "Answer: " << ansArray[i] << endl;
        // }

        size--;
    }
    fin.close();
    if ((correct) >= .6){
        cout << "At least 60% is correct. Stop.";
        cout << "percentage correct: " << correct *100.0 << "%";
    }else{
        cout << "percentage correct: " << correct *100.0 << "%";
    }
    //checks if csv is being read properly
    // for (int i = 0; i < 20; i++){
    //     cout << "Question: (" << i << ") " << qArray[i] << "\t" << "Answer: " << ansArray[i] << endl;
    // }
    cout << endl;
}
