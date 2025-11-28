/*
Create a program that calculates the hypotenuse of a right triangle after the user enters the lengths of the two short sides.
Specifications
    • Use the Pythagorean Theorem to calculate the length of the third side. The Pythagorean Theorem states that the square of the hypotenuse of a right-triangle is equal to the sum of the squares of the opposite sides:
    As a result, you can calculate side C like this:
	c = square_root(a2 + b2)
    • Side C should be rounded to a maximum of 3 decimal places.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

int main(void)
{
	//store sides
	double a, b, c;
	bool is_valid_input = false;

	std::cout << "Hypotenuse Calculator\n" << std::endl;

	while (!is_valid_input) {
		std::cout << "Side A: ";
		std::cin >> a;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again\n" << std::endl;
			continue;
		}

		std::cout << "Side B: ";
		std::cin >> b;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, try again\n" << std::endl;
			continue;
		}
		is_valid_input = true;
	}

	c = std::sqrt((a*a) + (b*b));

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Side C: " << c << std::endl;

	return 0;
}
