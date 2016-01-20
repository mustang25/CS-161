/*********************************************************************
 ** Author: Rob Navarro
 ** Date: May 16, 2015
 ** Description: A function that finds the mode of an Array
 *********************************************************************/


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int frequency = 0;
int highestFrequency;
vector<int> returnVector;
int vectorPosition = 0;

//This function finds the mode of an array and returns a vector of the modes
vector<int> findMode(int array[], int arrayLength){

    //This for loop finds the highest frequency in the array
    for(int count = 0; count < arrayLength; count++) {
        for (int count1 = 0; count1 < arrayLength; count1++){
            if(array[count]==array[count1]){
                frequency++;
                if(frequency > highestFrequency) {
                    highestFrequency = frequency;
                }
            }
        }
        frequency = 0;
    }

    //This sorts the array to allow us to store mode values in the vector easier.
    sort(array, array + arrayLength);

    //This adds the numbers of highest frequency to a return vector. Once a mode value is found
    //the highest frequency - 1 is added to the count value so that duplicates are not added.
    for(int count = 0; count < arrayLength; count++) {
        for (int count1 = 0; count1 < arrayLength; count1++){
            if(array[count]==array[count1]){
                frequency++;
                if(frequency == highestFrequency) {
                    returnVector.push_back(array[count]);
                    count += highestFrequency - 1;
                }
            }
        }
        frequency = 0;
    }


    return returnVector;
}
