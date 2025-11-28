/*
Create a program that calculates the estimated hours and minutes for a trip.
Specifications
    • The program should only accept integer entries like 200 and 65.
    • Assume that the user will enter valid data.
Hint
    • Use the division and modulus operators to get hours and minutes.
*/

#include <stdio.h>

int main(void)
{
	//variables to store input
	int miles, speed;

	puts("Travel Time Calculator\n");

	printf("Enter miles: ");
	scanf("%d", &miles);

	printf("Enter miles per hour: ");
	scanf("%d", &speed);

	puts("\nEstimated travel time");
	printf("Hours: %d\n", (miles/speed));
	printf("Minutes: %d\n", (miles%speed));

	return 0;
}
