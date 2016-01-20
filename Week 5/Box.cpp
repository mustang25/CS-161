/*********************************************************************
 ** Author: Rob Navarro
 ** Date: April 29, 2015
 ** Description: A class that finds the volume and surface area of a box
 *********************************************************************/

#include <iostream>
#include "Box.hpp"

//Default Constructor that sets l, w, and h to 1 for box
Box::Box(){
    length = 1;
    width = 1;
    height = 1;
}

//3 parameter constructor that sets l, w, h for box
Box::Box(double l, double w, double h) {
    length = l;
    width = w;
    height = h;
}

//Method that determines volume of box
double Box::getVolume() {
    return length * width * height;
}

//Method that determines surface area of box
double Box::getSurfaceArea() {
    return (2*length*width + 2*length*height + 2*width*height);
}
