/*
Create a program that allows you to perform simple calculations.
Specifications
    • If the specified year is a leap year, February has 29 days. Otherwise, it has 28. You can search the internet to learn how to calculate whether a year is a leap year.
    • If the user specifies an invalid month number, set the month name to “Invalid month number” and the number of days to 0.
    • Assume that the user will enter valid data for the year.
*/

#include <stdio.h>

//helper function
int is_feb(int year);

int main(void)
{
	//array of months
	char* months[] = {"Invalid month number", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	//store inputs and days in month
	int year, month, days;
	//store exit status of scanf
	int scanf_exit;

	puts("Month Selector\n");

	printf("Enter year:         ");
	scanf("%d", &year);

	printf("Enter month (1-12): ");
	scanf_exit = scanf(" %d", &month);

	if ((scanf_exit != 1) || (month <= 0) || (month > 12)) {
		printf("Month name:         %s\n", months[0]);
		printf("Days in month:      0\n");
		return 1;
	}

	if (month == 2) {
		days = is_feb(year);
	} else if (month <= 7) {
		days = (month % 2 == 0) ? 30 : 31;
	} else {
		days = (month % 2 == 0) ? 31 : 30;
	}

	printf("Month name:         %s\n", months[month]);
	printf("Days in month:      %d\n", days);
	puts("\nBye!");

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
