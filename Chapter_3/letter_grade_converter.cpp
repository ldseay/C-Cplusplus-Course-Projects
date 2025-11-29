/*
Create a program that converts number grades to letter grades.
Specifications
    • The grading criteria is as follows:
A    88-100
B    80-87
C    67-79
D    60-66
F     0-59
    • For grades less than 0, display a message that indicates that the numerical grade can’t be negative.
    • For grades greater than 100, display a message that indicates that the numerical grade is too large.
*/

#include <iostream>

//helper function
void get_letter_grade(int grade);

int main(void)
{
	int grade;
	
	std::cout << "Letter Grade Converter\n" << std::endl;

	std::cout << "Enter numerical grade (1-100): ";
	std::cin >> grade;

	if (std::cin.fail()) {
		std::cout << "Invaild Input: must be a number between 0 and 100.\n" << std::endl;
		std::cout << "Bye!" << std::endl;
	} else if (grade < 0) {
		std::cout << "Numerical grade can't be negative.\n" << std::endl;
		std::cout << "Bye!" << std::endl;
	} else if (grade > 100) {
		std::cout << "Numerical grade is too large.\n" << std::endl;
		std::cout << "Bye!" << std::endl;
	} else {
		get_letter_grade(grade);
	}
	return 0;
}

void get_letter_grade(int grade)
{
	char letter;

	if (grade >= 88) {
		letter = 'A';
	} else if (grade >= 80) {
		letter = 'B';
	} else if (grade >= 67) {
		letter = 'C';
	} else if (grade >= 60) {
		letter = 'D';
	} else {
		letter = 'F';
	}

	std::cout << "Letter grade: " << letter << std::endl;
	std::cout << "\nBye!" << std::endl;
}
