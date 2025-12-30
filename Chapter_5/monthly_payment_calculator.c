/*
Create a program that displays a table of monthly payments on a loan at varying interest rates and number of years.
Specifications
    • The interest rate should only have 1 decimal place.
    • The monthly payments should have 2 decimal places.
    • The first column should be left aligned, but all other columns should be right aligned.
    • The formula for calculating the monthly payment is:
monthly_payment = loan_amount * monthly_rate /
    (1 - 1 / pow((1 + monthly_rate), months))
    • Assume that the user will enter valid data.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	double loan_amount, monthly_rate;
	double yearly_rate[] = {0.03, 0.035, 0.04, 0.045, 0.05, 0.055};
	double years[] = {15, 20, 25, 30};

	puts("Monthly Payment Calculator\n");

	printf("Loan amount: ");
	scanf("%lf", &loan_amount);

	printf("\nYear");
	for (int i = 0; i < 6; i++) {
		printf("%12.1lf%%", (yearly_rate[i] * 100));
	}
	puts("");

	for (int i = 0; i < 4; i++) {
		printf("%.0lf  ", years[i]);
		for (int j = 0; j < 6; j++) {
			monthly_rate = loan_amount * (yearly_rate[j] / 12) / (1 - 1 / pow((1 + (yearly_rate[j] / 12)), (years[i] * 12)));
			printf("%13.2lf", monthly_rate);
		}
		puts("");
	}
	puts("\nBye!");

	return 0;
}
