#ifndef BOX_HPP
#define BOX_HPP

//Box class declaration
class Box
{
private:
    double length;
    double height;
    double width;
public:
    Box();
    Box(double, double, double);
    double getVolume();
    double getSurfaceArea();

};

#endif
