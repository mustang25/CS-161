/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 24, 2015
 ** Description: This defines the interface for the Item class.
 *********************************************************************/


#include <iostream>
#include <string>
#include "Item.hpp"
using namespace std;

//get/set methods for the item name
string Item::getName() {
    return name;
}

void Item::setName(string itemName) {
    name = itemName;
}

//get/set methods for the item price
double Item::getPrice() {
    return price;
}

void Item::setPrice(double inputPrice) {
    price = inputPrice;
}

//get/set methods for the item quantity
int Item::getQuantity() {
    return quantity;
}

void Item::setQuantity(int quantSet) {
    quantity = quantSet;
}

//default item constructor
Item::Item() {
    setName("");
    setPrice(0.0);
    setQuantity(0);
}

//constructor that allows the user to specify parameters
Item::Item(string userName, double userPrice, int userQuantity) {
    setName(userName);
    setPrice(userPrice);
    setQuantity(userQuantity);
}
