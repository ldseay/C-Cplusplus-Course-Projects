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

#include <stdio.h>

int main(void)
{
	//variables to store data from file
	float price, disc_pct, disc_amount, your_price;
	char code[12];

	//open files
	FILE* input_file = fopen("products.txt", "r");
	FILE* output_file = fopen("product_list.txt", "w");

	if (input_file == NULL || output_file == NULL) {
		perror("Error opening file: ");
		return 1;
	}
	//write to terminal
	puts("Product List\n");
	puts("Reading product data from products.txt file.");
	puts("Writing product data to product_list.txt file.");
	puts("\nBye!");

	//write to output file
	fputs("CURRENT PRODUCT LIST\n", output_file);
	fputs("==================================================\n", output_file);
	fputs("                      discount  discount      your\n", output_file);
	fputs("code           price   percent    amount     price\n", output_file);
	fputs("==================================================\n", output_file);

	//clear header line in input file
	int line;
	while ((line = fgetc(input_file)) != '\n');

	//read file
	while ((fscanf(input_file, "%s %f %f", code, &price, &disc_pct)) == 3) {
		disc_amount = price * disc_pct;
		your_price = price - disc_amount;

		fprintf(output_file, "%-9s %10.2f %9.0f %9.2f %9.2f\n", code, price, (disc_pct * 100), disc_amount, your_price);
	}
	//close files
	fclose(input_file);
	fclose(output_file);

	return 0;
}
