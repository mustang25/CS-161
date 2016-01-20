/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 7, 2015
 ** Description: A class that can find the length and slope of a line segment
 *********************************************************************/

#include "LineSegment.hpp"


//Constructor for LineSegment that sets
//endPoint1 and endPoint2
LineSegment::LineSegment(Point p1, Point p2) {
    setEnd1(p1);
    setEnd2(p2);
}

//Allows the user to set endPoint1 manually
void LineSegment::setEnd1(Point p3) {
    endPoint1 = p3;
}

//Allows the user to set endPoint2 manually
void LineSegment::setEnd2(Point p4) {
    endPoint2 = p4;
}

//Gets values for endPoint1
Point LineSegment::getEnd1() {
    return endPoint1;
}

//Gets values for endPoint2
Point LineSegment::getEnd2() {
    return endPoint2;
}

//Calculates the length of the line segment
double LineSegment::length() {
    return endPoint1.distanceTo(endPoint2);
}

//Calculates the slope of the line segment
double LineSegment::slope() {
    double x1, x2, y1, y2;
    x1 = endPoint1.getXCoord();
    x2 = endPoint2.getXCoord();
    y1 = endPoint1.getYCoord();
    y2 = endPoint2.getYCoord();

    return ((y2 - y1) / (x2 - x1));
}
