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

#include <stdio.h>

int main(void)
{
	float cost, shipping;
	int is_valid_input;

	puts("===============================================================");
	puts("Shipping Calculator");
	puts("===============================================================");

	printf("Cost of items ordered:  ");
	is_valid_input = scanf("%f", &cost);

	if (is_valid_input != 1) {
		puts("Invalid must input a number.\n\nBye!");
		return 1;
	} else if (cost < 0) {
		puts("You must enter a positive number.\n\nBye!");
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

	printf("Shipping cost:          %.2f\n", shipping);
	printf("Total cost:             %.2f\n", (shipping + cost));
	printf("\nBye!\n");

	return 0;
}
	
