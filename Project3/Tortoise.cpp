//
/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 3B

turtle class
*/
//
//
#include <iostream>
#include <cstdlib>
#include "Tortoise.hpp"

Tortoise::Tortoise(std::vector<int> patterns, int position){
    this->patterns = patterns;
    this->position = position;
}

Tortoise::Tortoise(int* arr, int size, int position){
    for (int i = 0; i < size; i++){
        patterns.push_back(arr[i]);
    }
    this->position = position;
}

Tortoise::Tortoise(){
    std::vector<int> p({3, 3, 3, 3, 3, -6, -6, 1, 1, 1});
    patterns = p;
    position = 0;
}

void Tortoise::move(){
    int r = rand() % patterns.size();
    position += patterns[r];
}

int Tortoise::getPosition() const{
    return position;
}

void Tortoise::setPosition(int position){
    this->position = position;
}