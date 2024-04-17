/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E6.20

sort with vectors
*/

// 

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b){
    int ai = 0; //a index
    int bi = 0; //b index
    vector<int> m; //merged vector
    while(ai < a.size() && bi < b.size()){
        if(a[ai] > b[bi]){
            m.push_back(b[bi]);
            bi++;
        }else{
            m.push_back(a[ai]);
            ai++;
        }
    }
    // cout << "ai: " << ai << endl;
    // cout << "a size: " << a.size() << endl;
    // cout << "bi: " << bi << endl;
    if(ai == a.size()){
        for (int i = bi; i < b.size(); i++){
            m.push_back(b[i]);
        }
    }else{
        for (int i = ai; i < a.size(); i++){
            m.push_back(a[i]);
        }
    }
    return m;
}

int main(){
    vector<int> a = {1, 3, 4, 5, 6, 7, 8, 56, 78};
    vector<int> b = {13, 47};

    vector<int> result = merge_sorted(a, b);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}