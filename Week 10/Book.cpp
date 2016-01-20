//
//  Book.cpp
//  Assignment 10
//
//  Created by Rob Navarro on 6/3/15.
//  Copyright (c) 2015 Rob Navarro. All rights reserved.
//

#include <iostream>
#include <string>
#include "Book.hpp"
using namespace std;

Book::Book(string idc, string t, string a) {
    idCode = idc;
    title = t;
    author = a;
    setCheckedOutBy(NULL);
    setRequestedBy(NULL);
    setLocation(ON_SHELF);
}

int Book::getCheckOutLength() {
    return CHECK_OUT_LENGTH;
}

string Book::getIdCode() {
    return idCode;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

void Book::setLocation(Locale l) {
    location = l;
}

Locale Book::getLocation() {
    return location;
}

Patron* Book::getCheckedOutBy() {
    return checkedOutBy;
};

void Book::setCheckedOutBy(Patron* person) {
    checkedOutBy = person;
};

Patron* Book::getRequestedBy() {
    return requestedBy;
};

void Book::setRequestedBy(Patron* by) {
    if (location == ON_SHELF) {
        location = ON_HOLD_SHELF;
    }
    requestedBy = by;
};

void Book::setDateCheckedOut(int date) {
    dateCheckedOut = date;
}

int Book::getDateCheckedOut() {
    return dateCheckedOut;
}

//int main() {
//    Book b1 ("abc", "The World", "Tom");
//    cout << b1.getLocation() << endl;
//    b1.setLocation(ON_HOLD_SHELF);
//    cout << b1.getLocation() << endl;
//    cout << (b1.getLocation() == ON_HOLD_SHELF);
//    return 0;
//
//}
