/*
Create a program that calculates the factorial of the number entered by the user.
Specifications
    • The exclamation point is used to identify a factorial. For example, the factorial of the number n is denoted by n!. Here’s how you calculate the factorial of the numbers 1 through 5:
1! = 1                   which equals 1
2! = 1 * 2               which equals 2
3! = 1 * 2 * 3           which equals 6
4! = 1 * 2 * 3 * 4       which equals 24
5! = 1 * 2 * 3 * 4 * 5   which equals 120
    • Use a for loop to calculate the factorial.
    • Assume that the user will enter valid numeric data.
    • The program should continue only if the user enters “y” or “Y”.
*/

#include <iostream>

int main(void)
{
	int input_number = 0;
	int factorial = 0;
	char is_continue = 'y';

	std::cout << "Factorial Calculator" << std::endl;

	while ((is_continue == 'y') || (is_continue == 'Y')) {
		std::cout << "\nEnter an integer (1-10): ";
		std::cin >> input_number;

		factorial = input_number;
		for (int i = 1; i < input_number; i++) {
			factorial = factorial * i;
		}
		std::cout << "The factorial of " << input_number << " is "
			<< factorial << ".\n" << std::endl;
		
		std::cout << "Continue? (y/n): ";
		std::cin >> is_continue;

		if ((std::cin.fail()) || (std::cin.peek() != EOF && std::cin.peek() != '\n')) {
			std::cout << "\nInvalid input!\n" << "Bye!" << std::endl;
			return 1;
		} else if ((is_continue != 'y') && (is_continue != 'Y')) {
			std::cout << "\nBye!" << std::endl;
		}
	}
	return 0;
}	
