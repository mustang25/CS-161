//
//  Patron.cpp
//  Assignment 10
//
//  Created by Rob Navarro on 6/3/15.
//  Copyright (c) 2015 Rob Navarro. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Patron.hpp"
using namespace std;

Patron::Patron(string idn, string n) {
    idNum = idn;
    name = n;
    fineAmount = 0.0;
}

string Patron::getIdNum() {
    return idNum;
}

string Patron::getName() {
    return name;
}

vector<Book*> Patron::getCheckedOutBooks() {
    return checkedOutBooks;
}

void Patron::addBook(Book* b) {
    checkedOutBooks.push_back(b);

}

void Patron::removeBook(Book* b) {
    for (int i = 0; i < checkedOutBooks.size(); i++) {
        if (b->getIdCode() == checkedOutBooks[i]->getIdCode()) {
            checkedOutBooks.erase(checkedOutBooks.begin() + i);
        }
    }
}

double Patron::getFineAmount() {
    return fineAmount;
}

void Patron::amendFine(double amount) {
    fineAmount += amount;
}

//int main() {
//    Book b1 ("a", "b", "c");
//    cout << b1.getAuthor() << endl;
//    Patron p1 ("rn25", "Rob Navarro");
//    cout << p1.getName() << endl;
//    b1.setCheckedOutBy(&p1);
//    cout << (*b1.getCheckedOutBy()).getName() << endl;
//}
