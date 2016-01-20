//
//  main.cpp
//  validation
//
//  Created by Rob Navarro on 5/30/15.
//  Copyright (c) 2015 Rob Navarro. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool stringIsInt (string testString1) {
    bool possibleInt = false;
    int intStart = 0;
    int intEnd = 0;
 
//looking for any part of the string that is not a space, +, -, or number
    for (int i = 0; i < testString1.length(); i++) {
        int testInt;
        testInt = testString1.at(i);
        if (testInt == 32 || (testInt >= 48 && testInt <= 57) || testInt == 43
            || testInt == 45 ) {
            possibleInt = true;
        }
        else
            return false;
    }

//finding the first +, -, or number in the string
    for (int i = 0; i < testString1.length(); i++) {
        int testInt = testString1.at(i);
        if (testInt == 43 || testInt == 45 || (testInt >= 48 && testInt <= 57)) {
            intStart = i;
            break;
        }
    }
    
//finding the last number in the string
    for (int i = (testString1.length() - 1); i >= 0; i--) {
        int testInt = testString1.at(i);
            if (testInt == 43 || testInt == 45 || (testInt >= 48 && testInt <= 57)) {
                intEnd = i;
                break;
        }
    }

//testing for more than one + or -
    int plusMinusCounter;
    for (int i = intStart; i < (intEnd + 1); i++) {
        int testInt = testString1.at(i);
        if (testInt == 43 || testInt == 45 ) {
            plusMinusCounter++;
            if (plusMinusCounter > 1) {
                return false;
            }
        }
    }
 
//testing for a + or - at any position that does not begin the int
    for (int i = (intStart + 1) ; i <= intEnd; i++) {
        int testInt = testString1.at(i);
        if (testInt == 43 || testInt == 45 ) {
            return false;
        }
    }

//testing for any spaces between digits in the int
    for (int i = intStart; i <= intEnd; i++) {
        int testInt = testString1.at(i);
        if ((testInt >=48 && testInt <= 57) && (i != intEnd)) {
            if (testString1.at(i + 1) == 32) {
                return false;
            }
        }
    }
    
    //testing for a string of length one that contains no digits
    for (int i = intStart; i <= intEnd; i++) {
        int testInt = testString1.at(i);
        if (intStart == intEnd) {
            if (testInt == 43 || testInt == 45)
                return false;
        }
    }
    return possibleInt;
}
bool stringIsFloat (string testString2) {
    bool possibleFloat = false;
    int intStart = 0;
    int intEnd = 0;
    
    //looking for any part of the string that is not a space, +, -, . ,  or number
    for (int i = 0; i < testString2.length(); i++) {
        int testInt;
        testInt = testString2.at(i);
        if (testInt == 32 || (testInt >= 48 && testInt <= 57) || testInt == 43
            || testInt == 45 || testInt == 46) {
            possibleFloat = true;
        }
        else
            return false;
    }
    
    //finding the first +, -, , . , or number in the string
    for (int i = 0; i < testString2.length(); i++) {
        int testInt = testString2.at(i);
        if (testInt == 43 || testInt == 45 || testInt == 46 || (testInt >= 48 && testInt <= 57)) {
            intStart = i;
            break;
        }
    }
    
    //finding the last number in the string
    for (int i = (testString2.length() - 1); i >= 0; i--) {
        int testInt = testString2.at(i);
        if (testInt == 43 || testInt == 45 || testInt == 46 ||(testInt >= 48 && testInt <= 57)) {
            intEnd = i;
            break;
        }
    }
    
    //testing for more than one + or -
    int plusMinusCounter;
    for (int i = intStart; i < (intEnd + 1); i++) {
        int testInt = testString2.at(i);
        if (testInt == 43 || testInt == 45 ) {
            plusMinusCounter++;
            if (plusMinusCounter > 1) {
                return false;
            }
        }
    }
    
    //testing for more than 1 period in the float
    int periodCounter = 0;
    for (int i = intStart; i < (intEnd); i++) {
        int testInt = testString2.at(i);
        if (testInt == 46) {
            periodCounter++;
        }
        if (periodCounter > 1) {
            return false;
        }
    }
    
    //testing for a string of length one that contains no digits
    for (int i = intStart; i <= intEnd; i++) {
        int testInt = testString2.at(i);
        if (intStart == intEnd) {
            if (testInt == 43 || testInt == 45 || testInt == 46)
            return false;
        }
    }
    
    //testing for a + or - at any position that does not begin the int
    for (int i = (intStart + 1) ; i <= intEnd; i++) {
        int testInt = testString2.at(i);
        if (testInt == 43 || testInt == 45 ) {
            return false;
        }
    }
    
    //testing for any space after period in the int
    for (int i = intStart; i <= intEnd; i++) {
        int testInt = testString2.at(i);
        if (testInt == 46 && i != intEnd) {
            if (testString2.at(i + 1) == 32) {
                return false;
            }
        }
    }
    
    //testing for any number after period in the int
    for (int i = intStart; i <= intEnd; i++) {
        int testInt = testString2.at(i);
        if (testInt == 46 ) {
            if ((testString2.at(i + 1)>= 48) && (testString2.at(i + 1)<=57)) {
            }
            else
                return false;
        }
    }
    
    //testing for any spaces between digits in the int
    for (int i = intStart; i <= intEnd; i++) {
        int testInt = testString2.at(i);
        if ((testInt >=48 && testInt <= 57) && (i != intEnd)) {
            if (testString2.at(i + 1) == 32) {
                return false;
            }
        }
    }
    return possibleFloat;
}

