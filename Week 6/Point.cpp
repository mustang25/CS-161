/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 7, 2015
 ** Description: The implementation for the point class.
 ** It includes get/set methods, as well as a distance function.
 *********************************************************************/

#include <iostream>
#include <cmath>
#include "Point.hpp"

//Set the x coordinate
void Point::setXCoord(double xSet) {
    x = xSet;
}

//Set the y coordinate
void Point::setYCoord(double ySet) {
    y = ySet;
}

//Default constructor
Point::Point(){
    setXCoord(0.0);
    setYCoord(0.0);
}

//Constructor that takes an x and y coordinate
Point::Point(double xCoord, double yCoord) {
    setXCoord(xCoord);
    setYCoord(yCoord);
}

//Gets the x coordinate
double Point::getXCoord(){
    return x;
}

//Get the y coordinate
double Point::getYCoord(){
    return y;
}

//Calculates the distance from one point to another
double Point::distanceTo(const Point& otherPoint){
    double x1, x2, y1, y2, dx, dy, distance;
    x1 = getXCoord();
    y1 = getYCoord();
    x2 = otherPoint.x;
    y2 = otherPoint.y;
    dx = x2 - x1;
    dy = y2 - y1;
    distance = sqrt(pow(dx,2.0) + pow(dy,2.0));

    return distance;
}
