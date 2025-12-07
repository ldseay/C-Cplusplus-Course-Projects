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

#include <stdio.h>

int main(void)
{
	int input_num = 0;
	int factorial = 0;
	char is_continue = 'y';
	char buffer_check;
	int is_valid_scanf = 0;

	puts("Factorial Calculator");

	while (is_continue == 'y' || is_continue == 'Y') {
		printf("\nEnter an integer (1-10): ");
		scanf("%d", &input_num);

		while ((buffer_check = getchar()) != '\n' && buffer_check != EOF);

		factorial = input_num;
		for (int i = 1; i < input_num; i++) {
			factorial = factorial * i;
		}
		printf("The factorial of %d is %d.\n", input_num, factorial);

		printf("\nContinue? (y/n): ");
		is_valid_scanf = scanf("%c", &is_continue);

		buffer_check = getchar();
		if ((is_valid_scanf != 1) || (buffer_check != '\n' && buffer_check != EOF)) {
			puts("\nInvalid input!\nBye!");
			return 1;
		}
	}
	puts("\nBye!");
	
	return 0;
}
