/*
Create a program that calculates the coins needed to make change for the specified number of cents.
Specifications
    • The program should display the minimum number of quarters, dimes, nickels, and pennies that one needs to make up the specified number of cents.
    • The program should continue only if the user enters “y” or “Y” to continue.
    • Assume that the user will enter a valid integer for the number of cents.
*/

#include <stdio.h>

int main(void)
{
	//store answer to continue question
	char answer = 'y';

	int scanf_is_valid;

	puts("Change Calculator");

	while ((answer == 'y') || (answer == 'Y')) {
		//store change and coin amounts
		int change = 0;
		int quarters = 0;
		int dimes = 0;
		int nickels = 0;
		int pennies = 0;

		printf("\nEnter number of cents (0-99): ");
		scanf("%d", &change);

		char character;
		while ((character = getchar()) != '\n' && character != EOF);

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
		printf("\nQuarters: %d\n", quarters);
		printf("Dimes:    %d\n", dimes);
		printf("Nickels:  %d\n", nickels);
		printf("Pennies:  %d\n", pennies);

		printf("\nContinue? (y/n): ");
		scanf_is_valid = scanf("%c", &answer);

		if (scanf_is_valid != 1) {
			puts("\n\nInvalid input!!!");
			return 1;
		} else if ((character = getchar()) != '\n' && character != EOF) {
			answer = 'n';
		}
	}
	puts("\nBye!");

	return 0;
}
