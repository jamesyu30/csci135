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

class Rectangle{
    public:
        Rectangle(double input_w, double input_h){
            height = input_h;
            width = input_w;
        }

        double get_perimeter(){
            return height*2 + width*2;
        }

        double get_area(){
            return height*width;
        }

        void resize(double factor){
            height*=factor;
            width*=factor;
        }

    private:
        double width;
        double height;
};

int main(){
    Rectangle r(6, 5);
    cout << "Perimeter: " << r.get_perimeter() << endl;
    cout << "Area: " << r.get_area() << endl;
    return 0;
}