/*
Create a program that calculates the area of various shapes.
Specifications
    • Use a switch statement to determine which shape was selected by the user.
    • Here are the formulas you can use to calculate the areas of the shapes:
circle_area = 3.14159 * radius2
square_area = height2
rectangle_area = height * width
    • Assume that the user will enter valid data for the radius, length, and width.
*/

#include <iostream>
#include <limits>

const double pi = 3.14159;

//helper functions
void circle(void);
void square(void);
void rectangle(void);

int main(void)
{
	int shape;

	std::cout << "AREA CALCULATOR\n"
		<< "1. Circle\n"
		<< "2. Square\n"
		<< "3. Rectangle\n" << std::endl;
	std::cout << "Menu item: ";
	std::cin >> shape;

	if ((std::cin.fail()) || (shape < 1) || (shape > 3)) {
		std::cout << "\nInvalid menu item!" << std::endl;
		return 1;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (shape) {
		case 1:
			circle();
			break;
		case 2:
			square();
			break;
		case 3:
			rectangle();
			break;
	}
	return 0;
}

void circle(void)
{
	double radius;
	std::cout << "\nCIRCLE\nRadius: ";
	std::cin >> radius;

	std::cout << "Area:   " << (pi * (radius * radius)) << std::endl;
	std::cout << "\nBye!" << std::endl;
}

void square(void)
{
	double height;
	std::cout << "\nSQUARE\nHeight: ";
	std::cin >> height;

	std::cout << "Area:   " << (height * height) << std::endl;
	std::cout << "\nBye!" << std::endl;
}

void rectangle(void)
{
	double height, width;
	std::cout << "\nRECTANGLE" << std::endl;
	
	std::cout << "Height: ";
	std::cin >> height;

	std::cout << "Width:  ";
	std::cin >> width;

	std::cout << "Area:   " << (height * width) << std::endl;
	std::cout << "\nBye!" << std::endl;
}
