//
//  Library.cpp
//  Assignment 10
//
//  Created by Rob Navarro on 6/3/15.
//  Copyright (c) 2015 Rob Navarro. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Library.hpp"
using namespace std;

Library::Library() {
    currentDate = 0;
}

void Library::addBook(Book* b) {
    holdings.push_back(b);
}

void Library::addPatron(Patron* p) {
    members.push_back(p);
}

Patron* Library::getPatron(string pID) {
    for (int i = 0; i < members.size(); i++) {
        if (pID == members[i]->getIdNum()) {
            return members[i];
        }
    }
    return NULL;
}

Book* Library::getBook(std::string bID) {
    for (int i = 0; i < holdings.size(); i++) {
        if (bID == holdings[i]->getIdCode()) {
            return holdings[i];
        }
    }
    return NULL;
}

string Library::checkOutBook(string pID, string bID) {
//    bool memberExist = false;
//    bool bookExist = false;
    Book* b = getBook(bID);
    Patron* p = getPatron(pID);

    if (b == NULL)
        return "book not found";

    if (p == NULL)
        return "patron not found";

//    for (int i = 0; i < members.size(); i++) {
//        if (pID == members[i]->getIdNum()){
//            memberExist = true;
//        }
//    }
//    if (!memberExist)
//        return "patron not found";
//
//
//    for (int i = 0; i < holdings.size(); i++) {
//        if (bID == holdings[i]->getIdCode()) {
//            bookExist = true;
//        }
//    }
//    if (!bookExist)
//        return "book not found";

    if (b->getLocation() == CHECKED_OUT)
        return "book already checked out";

    if (b->getLocation() == ON_HOLD_SHELF) {
        if (!(pID == (b->getRequestedBy())->getIdNum()))
            return "book on hold by other patron";
    }

    b->setRequestedBy(NULL);
    b->setLocation(CHECKED_OUT);
    p->addBook(b);
    b->setCheckedOutBy(p);
    b->setDateCheckedOut(currentDate);


    return "check out successful";
}

string Library::returnBook(string bID) {
    bool bookExist = false;
    Book* b = NULL;

    for (int i = 0; i < holdings.size(); i++) {
        if (bID == holdings[i]->getIdCode()) {
            bookExist = true;
            b = holdings[i];
        }
    }
    if (!bookExist)
        return "book not found";

    if (b->getLocation() == ON_SHELF || b->getLocation() == ON_HOLD_SHELF)
        return "book already in library";

    //patron who has book checked out
    Patron* p = b->getCheckedOutBy();

    //return book updates
    //remove the book from patrons checked out books
    p->removeBook(b);

    //If book is requested by someone update put it on the hold shelf
    if (b->getRequestedBy() != NULL) {
        b->setLocation(ON_HOLD_SHELF);
    }
    else
        b->setLocation(ON_SHELF);


    return "return successful";
}

string Library::requestBook(string pID, string bID) {
    Book* b = getBook(bID);
    Patron* p = getPatron(pID);

    if (b == NULL)
        return "book not found";

    if (p == NULL)
        return "patron not found";

    if ((b->getLocation() == ON_HOLD_SHELF) || !((b->getRequestedBy() == NULL)))
        return "book on hold by other patron";

    //If no return then,
    b->setRequestedBy(p);
    if (!(b->getLocation() == CHECKED_OUT))
        b->setLocation(ON_HOLD_SHELF);
    return "request successful";

}

string Library::payFine(string pID, double payment) {
    Patron* p = getPatron(pID);

    if (p == NULL)
        return "patron not found";

    p->amendFine(payment * -1);
    return "payment successful";

}

void Library::incrementCurrentDate() {
    currentDate++;
    double booksOverdue;
    for (int i = 0; i < members.size(); i++) {
        booksOverdue = 0;
        vector <Book*> testVector;
        testVector = members[i]->getCheckedOutBooks();
        for (int j = 0; j < testVector.size(); j++) {
            if ((currentDate - testVector[j]->getDateCheckedOut()) > testVector[j]->getCheckOutLength()) {
                booksOverdue++;
            }
        }
        members[i]->amendFine(booksOverdue * 0.10);
    }
}


//int main() {
//    Book b1 ("tw", "The World", "Tom");
//    cout << b1.getLocation() << endl;
//    cout << b1.getAuthor() << endl;
//    Patron p1 ("rn25", "Rob Navarro");
//    Patron p2 ("sm12", "Sam Wills");
//    cout << p1.getName() << endl;
//    Library test1;
////    b1.setRequestedBy(&p1);
////    cout << (b1.getRequestedBy())->getName() << endl;
//    test1.addBook(&b1);
//    test1.addPatron(&p1);
//    test1.addPatron(&p2);
//    cout << b1.getLocation() << endl;
//    cout << test1.checkOutBook("rn25", "tw") << endl;
//    cout << b1.getLocation() << endl;
//    test1.requestBook("sm12", "tw");
//    cout << (b1.getRequestedBy())->getName() << endl;
//    cout << test1.returnBook("tw") << endl;
//    cout << (b1.getRequestedBy())->getName() << endl;
//    cout << b1.getLocation() << endl;
//}
