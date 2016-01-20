//
//  Library.hpp
//  Assignment 10
//
//  Created by Rob Navarro on 6/3/15.
//  Copyright (c) 2015 Rob Navarro. All rights reserved.
//

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>
#include "Patron.hpp"

class Library
{
private:
    std::vector<Book*> holdings;
    std::vector<Patron*> members;
    int currentDate;
public:
    Library();
    void addBook(Book*);
    void addPatron(Patron*);
    std::string checkOutBook(std::string pID, std::string bID);
    std::string returnBook(std::string bID);
    std::string requestBook(std::string pID, std::string bID);
    std::string payFine(std::string pID, double payment);
    void incrementCurrentDate();
    Patron* getPatron(std::string pID);
    Book* getBook(std::string bID);
};

#endif
