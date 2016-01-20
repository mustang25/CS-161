/*********************************************************************
 ** Author: Rob Navarro
 ** Date: April 5, 2015
 ** Description: A program to convert temperatures from C to F
 *********************************************************************/


#include <iostream>
#include <string>
using namespace std;

int main()
{
    double userTemp,returnTemp;
    
    cout << "Please enter a Celsius temperature" << endl;
    cin >> userTemp;
    returnTemp = 1.8 * userTemp + 32;
    cout << returnTemp << endl;
    
    return 0;
}
