//
/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 3C

road class
*/
//
//
#include <iostream>
#include <cstdlib>
#include "Road.hpp"

Road::Road(){
    for (int i = 0; i < 70; i++){
        blocks.push_back(' ');
    }
}

Road::Road(int length){
    if(length < 0){
        length = 70;
    }
    for (int i = 0; i < length; i++){
        blocks.push_back(' ');
    }
} 

void Road::mark(int index, char ch){
    blocks[index] = ch;
}

void Road::display() const{
    for (int i = 0; i < blocks.size(); i++){
        std::cout << blocks[i];
    }
    std::cout << std::endl;
}

int Road::length() const{
    return blocks.size();
}