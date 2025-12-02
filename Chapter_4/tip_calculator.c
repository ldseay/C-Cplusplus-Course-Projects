/*
Create a program that calculates three options for an appropriate tip to leave after a meal at a restaurant.
Specifications
    • The program should calculate and display the cost of tipping at 15%, 20%, or 25%.
    • The program should round results to two decimal places.
    • Assume the user will enter valid data.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float cost;
	int tip_amounts[] = {15, 20, 25};
	int size_of_array = sizeof(tip_amounts) / sizeof(tip_amounts[0]);

	printf("Tip Calculator\n\nCost of meal: ");
	scanf("%f", &cost);

	for (int i = 0; i < size_of_array; i++) {
		printf("\n%d%%\n", tip_amounts[i]);
		printf("Tip amount:   %.2f\n", (cost * ((float)tip_amounts[i] / 100)));
		printf("Total amount: %.2f\n", ((cost * ((float)tip_amounts[i] / 100)) + cost));
	}
	return 0;
}
