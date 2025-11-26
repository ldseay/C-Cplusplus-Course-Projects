/*
Create a program that compares the unit prices for two sizes of laundry detergent sold at a grocery store.
Specifications
    • The formula for calculating price per ounce is:
price per ounce = price / ounces
    • The number of ounces for the comparison should be 64 and 32, but the code should store this data in two variables. That way, you can easily change the number of ounces for each comparison later, just by changing the value that’s stored in each variable.
    • The program should round the results to a maximum of two decimal places.
    • Assume the user will enter valid data.
*/

#include <stdio.h>

//global consts to store large and small size
const float l_size = 64;
const float s_size = 32;

int main(void)
{
	//store large and small price
	float l_price, s_price;

	puts("Price Comparison\n");

	printf("Price of %.0f ounce size:  ", l_size);
	scanf("%f", &l_price);

	printf("Price of %.0f ounce size:  ", s_size);
	scanf("%f", &s_price);
	
	printf("\nPrice per ounce (%.0f oz): %.2f\n", l_size, (l_price/l_size));
	printf("Price per ounce (%.0f oz): %.2f\n", s_size, (s_price/s_size));

	return 0;
}
