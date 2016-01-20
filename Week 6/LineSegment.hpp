/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 7, 2015
 ** Description: This is the interface for the LineSegment class.
 *********************************************************************/

#ifndef LineSegment_hpp
#define LineSegment_hpp
#include "Point.hpp"

class LineSegment {
private:
    Point endPoint1;
    Point endPoint2;
public:
    LineSegment(Point, Point);
    void setEnd1(Point);
    Point getEnd1();
    void setEnd2(Point);
    Point getEnd2();
    double length();
    double slope();


};

#endif
