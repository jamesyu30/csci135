//
/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 3A

hare class
*/
//
//
#include <iostream>
#include <cstdlib>
#include "Hare.hpp"

Hare::Hare(std::vector<int> patterns, int position){
    this->patterns = patterns;
    this->position = position;
}

Hare::Hare(int* arr, int size, int position){
    for (int i = 0; i < size; i++){
        patterns.push_back(arr[i]);
    }
    this->position = position;
}

Hare::Hare(){
    std::vector<int> p({0, 0, 9, 9, -12, 1, 1, 1, -2, -2});
    patterns = p;
    position = 0;
}

void Hare::move(){
    int r = rand() % patterns.size();
    position += patterns[r];
}

int Hare::getPosition() const{
    return position;
}

void Hare::setPosition(int position){
    this->position = position;
}