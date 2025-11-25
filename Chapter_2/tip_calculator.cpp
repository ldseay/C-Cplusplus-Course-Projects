/*
Create a program that calculates the tip and total for a meal at a restaurant.
Specifications
    • The formula for calculating the tip amount is:
	tip = cost of meal * (tip percent / 100)
    • The program should accept decimal entries like 52.31 and 15.5.
    • The program should round the results to a maximum of two decimal places.
    • Assume the user will enter valid data.
*/

#include <iostream>
#include <iomanip>

int main(void)
{
	float m_cost, tip_percent, tip_amount, t_cost;

	std::cout << "Tip Calculator\n" << std::endl;

	std::cout << "Cost of meal: ";
	std::cin >> m_cost;

	std::cout << "Tip percent:  ";
	std::cin >> tip_percent;

	tip_amount = m_cost * (tip_percent / 100);
	t_cost = m_cost + tip_amount;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nTip amount:   " << tip_amount << std::endl;
	std::cout << "Total amount: " << t_cost << std::endl;

	return 0;
}
