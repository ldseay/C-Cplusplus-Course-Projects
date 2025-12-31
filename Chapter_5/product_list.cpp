/*
Create a program that reads data from an unformatted, tab-delimited file, performs some calculations on that data, and writes the resulting data to another file that’s formatted and uses spaces to align the columns.
Specifications
    • Provided a tab-delimited file named products.txt that contains the product data shown here:
CODE	PRICE		DISC_PCT	
strat	699.5		.3
les_paul	1199		.3
sg		2517		.52
fg700s	489.99		.38
washburn	299.0		.0
    • The program should read the data from the products.txt file, calculate the discount amount and list price from this data, and write the result to a text file named product_list.txt. This data should be formatted and aligned using spaces as shown here:
CURRENT PRODUCT LIST
==================================================
                      discount  discount      your
code           price   percent    amount     price
==================================================
strat         699.50        30    209.85    489.65
les_paul     1199.00        30    359.70    839.30
sg           2517.00        52   1308.84   1208.16
fg700s        489.99        38    186.20    303.79
washburn      299.00         0      0.00    299.00
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

int main(void)
{
	//variables to store data from the file
	float price, disc_pct, disc_amount, your_price;
	std::string code;

	//open file objects
	std::ifstream input_file;
	std::ofstream output_file;
	input_file.open("products.txt");
	output_file.open("product_list.txt");

	//write to console
	std::cout << "Product List\n\n"
		<< "Reading product data from products.txt file.\n"
		<< "Writing product data to product_list.txt file.\n\n"
		<< "Bye!\n";

	//write header to output file
	output_file << "CURRENT PRODUCT LIST\n"
		<< "==================================================\n"
		<< "                      discount  discount      your\n"
		<< "code           price   percent    amount     price\n"
		<< "==================================================\n";

	std::string first_line; //used to skip the first line of input file
	std::getline(input_file, first_line);
	
	while (input_file >> code >> price >> disc_pct) {
		disc_amount = price * disc_pct;
		your_price = price - disc_amount;

		output_file << std::fixed << std::setprecision(2);
		output_file << std::left << std::setw(8) << code 
			<< std::right << std::setw(12) << price
			<< std::setprecision(0) << std::right << std::setw(10) << (disc_pct * 100) 
			<< std::setprecision(2) << std::right << std::setw(10) << disc_amount 
			<< std::right << std::setw(10) << your_price << '\n';
	}
	//close files
	input_file.close();
	output_file.close();

	return 0;
}

