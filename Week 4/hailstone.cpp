/*********************************************************************
 ** Author: Rob Navarro
 ** Date: April 25, 2015
 ** Description: A function that solves the hailstone puzzle.
 *********************************************************************/

#include <iostream>

int hailstone(int start) {
    int steps = 0;
    bool tf = false;

// A while loop that runs until the start value is = 1.
// The steps are counted to determine the return value.
// If the start value modulo by 2 is 0 then the value is positive

    while (!tf) {
        if (start == 1)
            tf = true;

        else if (start % 2 == 0) {
            start = start / 2;
            steps++;
        }

        else {
            start = (start * 3) + 1;
            steps++;
        }

    }
    return steps;
}

//int main() {
//    std::cout << hailstone(11);
//    return 0;
//}
