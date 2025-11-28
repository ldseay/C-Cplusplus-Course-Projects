/*
Create a program that calculates the estimated hours and minutes for a trip.
Specifications
    • The program should only accept integer entries like 200 and 65.
    • Assume that the user will enter valid data.
Hint
    • Use the division and modulus operators to get hours and minutes.
*/

#include <iostream>

int main(void)
{
	//variables to store input
	int miles, speed;

	std::cout << "Travel Time Calculator\n" << std::endl;

	std::cout << "Enter miles: ";
	std::cin >> miles;

	std::cout << "Enter miles per hour: ";
	std::cin >> speed;

	std::cout << "\nEstimated travel time\n";
	std::cout << "Hours: " << (miles/speed) << std::endl;
	std::cout << "Minutes: " << (miles%speed) << std::endl;

	return 0;
}
