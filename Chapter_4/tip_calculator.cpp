/*
Create a program that calculates three options for an appropriate tip to leave after a meal at a restaurant.
Specifications
    • The program should calculate and display the cost of tipping at 15%, 20%, or 25%.
    • The program should round results to two decimal places.
    • Assume the user will enter valid data.
*/

#include <iostream>
#include <iomanip>
#include <array>

int main(void)
{
	float cost;
	//array to hold tip percents
	std::array<int, 3> tip_percents = {15, 20, 25};

	std::cout << "Tip Calculator\n\n"
		<< "Cost of meal: ";
	std::cin >> cost;

	std::cout << std::fixed << std::setprecision(2);
	for (int percent : tip_percents) {
		std::cout << '\n' << percent << '%' << std::endl;
		std::cout << "Tip amount:   " << (cost * (static_cast<float>(percent) / 100)) << std::endl;
		std::cout << "Total amount: " << ((cost * (static_cast<float>(percent) / 100)) + cost)
			<< std::endl;
	}
	return 0;
}
