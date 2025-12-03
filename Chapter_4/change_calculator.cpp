/*
Create a program that calculates the coins needed to make change for the specified number of cents.
Specifications
    • The program should display the minimum number of quarters, dimes, nickels, and pennies that one needs to make up the specified number of cents.
    • The program should continue only if the user enters “y” or “Y” to continue.
    • Assume that the user will enter a valid integer for the number of cents.
*/

#include <iostream>
#include <string>

int main(void)
{
	//store user answer to continue
	std::string answer = "y";

	std::cout << "Change Calculator\n" << std::endl;

	while ((answer == "y") || (answer == "Y")) {	
		//store number of coins and total change
		int quarters = 0;
		int dimes = 0;
		int nickels = 0;
		int pennies = 0;
		int change = 0;
		
		std::cout << "Enter number of cents (0-99): ";
		std::cin >> change;

		while (change > 0) {
			if (change >= 25) {
				change -= 25;
				quarters++;
			} else if (change >= 10) {
				change -= 10;
				dimes++;
			} else if (change >= 5) {
				change -= 5;
				nickels++;
			} else if (change >= 1) {
				change--;
				pennies++;
			}
		}
		
		std::cout << "\nQuarters: " << quarters << std::endl;
		std::cout << "Dimes:    " << dimes << std::endl;
		std::cout << "Nickels:  " << nickels << std::endl;
		std::cout << "Pennies:  " << pennies << std::endl;

		std::cout << "\nContinue? (y/n): ";
		std::cin >> answer;

		if (std::cin.fail()) {
			std::cout << "\nInvalid input!!!\n";
			return 1;
		}
		std::cout << std::endl;
	}
	std::cout << "Bye!" << std::endl;
	
	return 0;
}
