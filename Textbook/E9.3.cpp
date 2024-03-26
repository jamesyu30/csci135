/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: E9.5

making a rectangle class
*/

// 
#include <iostream>
using namespace std;

class Circuit{
    public:
        int get_first_switch_state(){
            return first_switch;
        }

        int get_second_switch_state(){
            return second_switch;
        }

        int get_lamp_state(){
            return lamp_state;
        }

        void toggle_first_switch(){
            first_switch = 1 - first_switch;
            // if (first_switch == 0){
            //     first_switch = 1;
            // }else{
            //     first_switch = 0;
            // }

            if (first_switch^second_switch){
                lamp_state = 1;
            }else{
                lamp_state = 0;
            }
        }

        void toggle_second_switch(){
            second_switch = 1 - second_switch;
            // if (second_switch == 0){
            //     second_switch = 1;
            // }else{
            //     second_switch = 0;
            // }

            if (first_switch^second_switch){
                lamp_state = 1;
            }else{
                lamp_state = 0;
            }
        }
    private:
        int first_switch = 0;
        int second_switch = 0;
        int lamp_state = 0;
};

int main(){
    return 0;
}