/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 7, 2015
 ** Description: This defines the interface for the Point class.
 *********************************************************************/

#ifndef Point_hpp
#define Point_hpp

class Point {
private:
    double x;
    double y;
public:
    Point();
    Point(double, double);
    void setXCoord(double);
    double getXCoord();
    void setYCoord(double);
    double getYCoord();
    double distanceTo(const Point&);
    
};

#endif
