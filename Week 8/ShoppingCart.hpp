/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 7, 2015
 ** Description: This defines the interface for the ShoppingCart class.
 *********************************************************************/


#ifndef ShoppingCart_hpp
#define ShoppingCart_hpp
#include "Item.hpp"

class ShoppingCart {
private:
    int arrayEnd;
    Item* itemArray[100];
    double total;
    
public:
    ShoppingCart();
    void addItem(Item*);
    double totalPrice();
    
};



#endif
