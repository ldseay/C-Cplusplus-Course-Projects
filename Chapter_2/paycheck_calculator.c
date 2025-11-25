/*
Create a program that calculates a user’s weekly gross and take-home pay.
Specifications
    • The formula for calculating gross pay is:
gross pay = hours worked * hourly rate
    • The formula for calculating tax amount is:
tax amount = gross pay * (tax rate / 100)
    • The formula for calculating take home pay is:
take home pay = gross pay – tax amount
    • The tax rate should be 18%, but the code should store the tax rate in a variable. That way, you can easily change the tax rate later, just by changing the value that’s stored in the variable.
    • The program should accept decimal entries like 35.5 and 14.25.
    • The program should round the results to a maximum of two decimal places.
    • Assume the user will enter valid data.
*/

#include <stdio.h>

const float tax_rate = 18;

int main(void)
{
	float hours, rate, gross, tax_amount, net_pay;

	puts("Paycheck Calculator\n");

	printf("Hours Worked:    ");
	scanf("%f", &hours);

	printf("Hourly Pay Rate: ");
	scanf("%f", &rate);

	gross = hours * rate;
	tax_amount = gross * (tax_rate / 100);
	net_pay = gross - tax_amount;

	printf("\nGross Pay:       %.2f\n", gross);
	printf("Tax Rate:        %.0f%\n", tax_rate);
	printf("Tax Amount:      %.2f\n", tax_amount);
	printf("Take Home Pay:   %.2f\n", net_pay);

	return 0;
}

