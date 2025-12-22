/*
Create a program that reads the sales for 12 months from a file and calculates the total yearly sales as well as the average monthly sales.
Specifications
    • Your provided a tab-delimited file named monthly_sales.txt that contains the month and sales data shown here:
    Jan     14317.41        Feb     3903.32 Mar     1073.01 Apr     3463.28 May     2429.52 Jun     4324.70 Jul     9762.31 Aug     25578.39        Sep     2437.95 Oct     6735.63 Nov     288.11  Dec     2497.49

    • Round the results of the monthly average to a maximum of 2 decimal digits and make sure that a minimum of 2 decimal digits are displayed on the console.
    • Right-align the columns that display the monthly sales, the yearly total, and the monthly average.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define MON 12

//helper functions
void print_sales(std::string (&months)[MON], float* sales);
void print_yearly(float* sales);

int main(void)
{
	std::string months[MON];
	float sales[MON];
	std::string sale;
	
	//load months and sales from file
	std::ifstream fh;  
	fh.open("monthly_sales.txt");

	for (int i = 0; i < MON; i++) {
		std::getline(fh, months[i], '\t');
		std::getline(fh, sale, '\t');
		sales[i] = stof(sale);
	}
	fh.close();

	char user_command = 'a';

	std::cout << "Monthly Sales" << std::endl;
	while (user_command != 'x') {
		std::cout << "\nCOMMAND MENU" << std::endl;
		std::cout << "m - View monthly sales" << std::endl;
		std::cout << "y - View yearly summary" << std::endl;
		std::cout << "x - Exit program\n" << std::endl;

		std::cout << "Command: ";
		std::cin >> user_command;

		if (user_command == 'm') {
			print_sales(months, sales);
		} else if (user_command == 'y') {
			print_yearly(sales);
		}
	}
	std::cout << "\nBye!" << std::endl;
}

//prints monthly sales
void print_sales(std::string (&months)[MON], float* sales)
{
	std::cout << "\nMONTHLY SALES" << std::endl;

	for (int i = 0; i < MON; i++) {
		std::cout << std::fixed << std::setprecision(2);
		std::cout << std::left << months[i] << '\t' << std::right 
			<< std::setw(15) << sales[i] << std::endl;
	}
}

//print yearly summary
void print_yearly(float* sales)
{
	float total = 0;
	float average;

	for (int i = 0; i < MON; i++) {
		total = total + sales[i];
	}
	average = total / MON;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nYEARLY SUMMARY" << std::endl;
	std::cout << std::left << "Yearly total:   " << std::right 
		<< std::setw(15) << total << std::endl;
	std::cout << std::left << "Monthly average:" << std::right 
		<< std::setw(15) << average << std::endl;
}
