/*
Create a program that compares the unit prices for two sizes of laundry detergent sold at a grocery store.
Specifications
    • The formula for calculating price per ounce is:
price per ounce = price / ounces
    • The number of ounces for the comparison should be 64 and 32, but the code should store this data in two variables. That way, you can easily change the number of ounces for each comparison later, just by changing the value that’s stored in each variable.
    • The program should round the results to a maximum of two decimal places.
    • Assume the user will enter valid data.
*/

#include <iostream>
#include <iomanip>

//store large and small size as global const
const float l_size = 64;
const float s_size = 32;

int main(void)
{
	//store large and small price
	float l_price, s_price;

	std::cout << "Price Comparison\n" << std::endl;

	std::cout << "Price of " << l_size << " ounce size:  ";
	std::cin >> l_price;

	std::cout << "Price of " << s_size << " ounce size:  ";
	std::cin >> s_price;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nPrice per ounce (" << l_size << " oz): " << (l_price/l_size) << std::endl;
	std::cout << "Price per ounce (" << s_size << " oz): " << (s_price/s_size) << std::endl;

	return 0;
}
