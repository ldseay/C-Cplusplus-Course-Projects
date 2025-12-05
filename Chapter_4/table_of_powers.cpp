/*
Create a program that displays a table of squares and cubes for the specified range of numbers.
Specifications
    • Use tabs to align the columns.
    • Assume that the user will enter valid integers.
    • Make sure the user enters a start integer that’s less than the stop integer. If the user enters a start integer that’s greater than the stop integer, display an error message and give the user a chance to enter the integers again.
*/

#include <iostream>
#include <cmath>

int main(void)
{
	long double squared, cubed;
	int start, stop;
	bool is_valid_range = false;

	std::cout << "Table of Powers" << std::endl;

	while (! is_valid_range) {
		std::cout << "\nEnter start number: ";
		std::cin >> start;

		std::cout << "Enter stop number:  ";
		std::cin >> stop;

		if (stop < start) {
			std::cout << "\nStart number must be less than stop number.\n"
				<< "Please try again." << std::endl;
		} else {
			is_valid_range = true;
		}
	}
	std::cout << "\nNumber  Squared Cubed\n";
	std::cout << "======  ======= =====\n";

	for (int i = start; i <= stop; i++) {
		squared = std::powl(start, 2);
		cubed = std::powl(start, 3);

		std::cout << start << '\t' << squared << '\t'
			<< cubed << std::endl;
		start++;
	}
	return 0;
}

