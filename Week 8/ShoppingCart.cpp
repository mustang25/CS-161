/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 24, 2015
 ** Description: The implementation for the ShoppingCart class.
 *********************************************************************/


#include <iostream>
#include <string>
#include "ShoppingCart.hpp"
using namespace std;

//default constructor
ShoppingCart::ShoppingCart() {
    for (int i = 0; i < 100; i++) {
        itemArray[i] = NULL;
    }
    arrayEnd = 0;
}

//method to add an item to the cart array
void ShoppingCart::addItem(Item* itemAdd) {
    itemArray[arrayEnd] = itemAdd;
    arrayEnd++;

}

//find the total price for all of the shopping cart items.
double ShoppingCart::totalPrice() {
    total = 0.0;
    for (int i =0; i < arrayEnd; i++) {
        total += itemArray[i]->getPrice() * itemArray[i]->getQuantity();
    }
    return total;
}


