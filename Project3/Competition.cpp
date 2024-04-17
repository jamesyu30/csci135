//
/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 3D


*/
//
//
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Competition.hpp"

Competition::Competition(){
    rabbit = Hare();
    tor = Tortoise();
    lane = Road();
}

Competition::Competition(Hare coney, Tortoise cooter, int length){
    rabbit = coney;
    tor = cooter;
    lane = Road(length);
}

void Competition::play(){
    int lastBlock = lane.length()-1;
    int round = 1;
    while(rabbit.getPosition() < lastBlock && tor.getPosition() < lastBlock){
        rabbit.move();
        tor.move();
        //adjusting rabbit position
        if(rabbit.getPosition() < 0){
            rabbit.setPosition(0);
        }
        if (rabbit.getPosition() > lastBlock){
            rabbit.setPosition(lastBlock);
        }

        //adjusting turtle position
        if(tor.getPosition() < 0){
            tor.setPosition(0);
        }
        if (tor.getPosition() > lastBlock){
            tor.setPosition(lastBlock);
        }

        if (tor.getPosition() == rabbit.getPosition()){
            lane.mark(tor.getPosition(), 'T');
            std::cout << std::setw(2) << round;
            lane.display();
            std::cout << "Ouch, Tortoise bites Hare." << std::endl;
        }else{
            lane.mark(tor.getPosition(), 'T');
            lane.mark(rabbit.getPosition(), 'H');
            std::cout << std::setw(2) << round;
            lane.display();
        }

        //clearing road
        lane.mark(tor.getPosition(), ' ');
        lane.mark(rabbit.getPosition(), ' ');
        round++;
    }

    if(tor.getPosition() == lastBlock && rabbit.getPosition() == lastBlock){
        std::cout << "It is a tie" << std::endl;
    }else if(rabbit.getPosition() == lastBlock){
        std::cout << "Yuck. Hare wins." << std::endl;
    }else{
        std::cout << "Yay!!! Tortoise wins." << std::endl;
    }

}