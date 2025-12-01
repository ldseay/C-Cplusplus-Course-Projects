/*
Create a program that allows you to perform simple calculations.
Specifications
    • If the specified year is a leap year, February has 29 days. Otherwise, it has 28. You can search the internet to learn how to calculate whether a year is a leap year.
    • If the user specifies an invalid month number, set the month name to “Invalid month number” and the number of days to 0.
    • Assume that the user will enter valid data for the year.
*/

#include <iostream>
#include <array>
#include <string>

//helper function
int is_feb(int year);

int main(void)
{
	//array of months
	std::array<std::string, 13> months = {"Invalid month number", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	//store user input
	int year, month, days;

	std::cout << "Month Selector\n" << std::endl;

	std::cout << "Enter year:         ";
	std::cin >> year;

	std::cout << "Enter month (1-12): ";
	std::cin >> month;

	if ((std::cin.fail()) || (month < 0) || (month > 12)) {
		std::cout << "Month name:         " << months[0] << std::endl;
		std::cout << "Days in month:      0\n\nBye!" << std::endl;
		return 1;
	}

	if (month == 2) {
		days = is_feb(year);
	} else if (month <= 7) {
		days = (month % 2 == 0) ? 30 : 31;
	} else {
		days = (month % 2 == 0) ? 31: 30;
	}

	std::cout << "Month name:         " << months[month] << std::endl;
	std::cout << "Days in month:      " << days << std::endl;
	std::cout << "\nBye!" << std::endl;

	return 0;
}

int is_feb(int year)
{
	if (year % 4 == 0) {
		return 29;
	} else {
		return 28;
	}
}
