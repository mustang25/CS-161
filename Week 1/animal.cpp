/**********************************************************************
** Author: Robert Navarro
** Date: March 31, 2015
** Description: Assignment 1
**********************************************************************/

#include <iostream>
#include <string>

//a simple example program
int main()
{
	std::string faveAnimal;
	std::cout << "Please enter your favorite animal." << std::endl;

	std::cin >> faveAnimal;
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout <<"."<<std::endl;

	return 0;
}
