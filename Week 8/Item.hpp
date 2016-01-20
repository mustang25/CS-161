/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 24, 2015
 ** Description: This defines the interface for the Item class.
 *********************************************************************/

#ifndef Item_hpp
#define Item_hpp
using namespace std;

class Item{
private:
    string name;
    double price;
    int quantity;
public:
    Item();
    Item(string, double, int);
    string getName();
    void setName(string);
    double getPrice();
    void setPrice(double);
    int getQuantity();
    void setQuantity(int);
};


#endif
