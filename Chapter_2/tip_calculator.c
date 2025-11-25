/*
Create a program that calculates the tip and total for a meal at a restaurant.
Specifications
    • The formula for calculating the tip amount is:
	tip = cost of meal * (tip percent / 100)
    • The program should accept decimal entries like 52.31 and 15.5.
    • The program should round the results to a maximum of two decimal places.
    • Assume the user will enter valid data.
*/

#include <stdio.h>

int main(void)
{
	float m_cost, tip_percent;

	puts("Tip Calculator\n");

	printf("Cost of meal: ");
	scanf("%f", &m_cost);

	printf("Tip percent:  ");
	scanf("%f", &tip_percent);

	printf("\nTip amount:   %.2f\n", m_cost * (tip_percent / 100));
	printf("Total amount: %.2f\n", (m_cost * (tip_percent / 100)) + m_cost);

	return 0;
}
