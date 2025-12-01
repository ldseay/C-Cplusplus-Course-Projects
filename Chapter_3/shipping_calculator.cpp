/*
Create a program that calculates the total cost of an order including shipping.
Specifications
    • Use the following table to calculate shipping cost:
COST OF ITEMS    SHIPPING COST
==============================
00.00-29.99      5.95
30.00-49.99      7.95
50.00-74.99      9.95
75.00 or more    FREE
    • If the user enters a number that’s less than zero, display an error message.
*/

#include <iostream>
#include <iomanip>

int main(void)
{
	float cost, shipping;

	std::cout << "===============================================================" << std::endl;
	std::cout << "Shipping Calculator\n";
	std::cout << "===============================================================" << std::endl;

	std::cout << "Cost of items ordered:  ";
	std::cin >> cost;

	if (std::cin.fail()) {
		std::cout << "Invalid input must input a number.\n\nBye!" << std::endl;
		return 1;
	} else if (cost < 0) {
		std::cout << "You must enter a positive number.\n\nBye!" << std::endl;
		return 2;
	}

	if (cost >= 75) {
		shipping = 0;
	} else if (cost >= 50) {
		shipping = 9.95;
	} else if (cost >= 30) {
		shipping = 7.95;
	} else {
		shipping = 5.95;
	}

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Shipping cost:          " << shipping << std::endl;
	std::cout << "Total cost:             " << (shipping + cost) << std::endl;
	std::cout << "\nBye!" << std::endl;

	return 0;
}
