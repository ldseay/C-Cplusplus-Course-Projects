/*
Create a program that calculates the amount of time and fuel for a 1980 Cessna 172N to fly a specified distance.
Specifications
    • Assume that a 1980 Cessna 172N can fly 120 nautical miles (knots) per hour.
    • Assume that a 1980 Cessna 172N burns 8.4 gallons of gas per hour.
    • For safety, add a half hour to the flight time when calculating the amount of required fuel.
    • Round the amount of required fuel to 1 decimal place. For safety, always round up, never down.
    • Assume that the user will enter valid data.
*/

#include <stdio.h>

const float miles_per_hour = 120;
const float gallons_per_hour = 8.4;
const float safety_fuel = 0.5;

int main(void)
{
	float miles, hours, minutes, gallons;
	char answer = 'y';
	char clear_input;

	puts("Aircraft Fuel Calculator");
	
	while (answer == 'y') {
		printf("\nDistance in nautical miles: ");
		scanf("%f", &miles);
		
		while ((clear_input = getchar()) != '\n' && clear_input != EOF);

		hours = (int)miles / (int)miles_per_hour;
		minutes = ((int)miles % (int)miles_per_hour) / miles_per_hour; //must multiply by 60 mins in a hour
		gallons = (hours + minutes + safety_fuel) * gallons_per_hour;

		printf("Flight time: %.0f hour(s) and %.0f minute(s)\n", hours, (minutes * 60));
		printf("Required fuel: %.1f gallons\n\n", gallons);

		printf("Continue? (y/n): ");
		scanf("%c", &answer);

		while((clear_input = getchar()) != '\n' && clear_input != EOF);
	}
	puts("\nBye!");

	return 0;
}
