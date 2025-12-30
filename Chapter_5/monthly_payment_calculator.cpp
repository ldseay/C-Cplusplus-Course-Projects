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

#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>

int main(void)
{
	double loan_amount, monthly_payment;
	std::array<double, 6> monthly_rate = {0.03, 0.035, 0.04, 0.045, 0.05, 0.055};
	std::array<int, 4> years = {15, 20, 25, 30};

	std::cout << "Monthly Payment Calculator\n" << std::endl;
	
	std::cout << "Loan amount: ";
	std::cin >> loan_amount;
	std::cout << std::endl;

	std::cout << "Year ";
	std::cout << std::fixed << std::setprecision(1);
	for (double rate : monthly_rate) {
		std::cout << std::right << std::setw(10) << (rate * 100) << '%';
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(2);
	for (int year : years) {
		std::cout << year << "   ";
		for (double rate : monthly_rate) {
			monthly_payment = loan_amount * (rate / 12) / (1 - 1 / std::pow((1 + (rate / 12)), (double)(year * 12)));
			std::cout << std::right << std::setw(11) << monthly_payment;
		}
		std::cout << std::endl;
	}

	std::cout <<"\nBye!" << std::endl;

	return 0;
}
