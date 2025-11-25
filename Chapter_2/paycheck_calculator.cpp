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

#include <iostream>
#include <iomanip>

const float tax_rate = 18;

int main(void)
{
	//variables to store hours worked and pay rate
	float hours, rate, gross, tax_amount, net_pay;

	std::cout << "Paycheck Calculator\n" << std::endl;
	
	std::cout << "Hours Worked:    ";
	std::cin >> hours;

	std::cout << "Hourly Pay Rate: ";
	std::cin >> rate;

	gross = hours * rate;
	tax_amount = gross * (tax_rate / 100);
	net_pay = gross - tax_amount;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Gross Pay:       " << gross << '\n';
	std::cout << "Tax Rate:        " << tax_rate << "%\n";
	std::cout << "Tax Amount:      " << tax_amount << '\n';
	std::cout << "Take Home Pay:   " << net_pay << std::endl;

	return 0;
}	
