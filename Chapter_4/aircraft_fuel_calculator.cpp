/*
Create a program that calculates the amount of time and fuel for a 1980 Cessna 172N to fly a specified distance.
Specifications
    • Assume that a 1980 Cessna 172N can fly 120 nautical miles (knots) per hour.
    • Assume that a 1980 Cessna 172N burns 8.4 gallons of gas per hour.
    • For safety, add a half hour to the flight time when calculating the amount of required fuel.
    • Round the amount of required fuel to 1 decimal place. For safety, always round up, never down.
    • Assume that the user will enter valid data.
*/

#include <iostream>
#include <iomanip>

const float miles_per_hour = 120;
const float gallons_per_hour = 8.4;
const float safety_fuel = .5;

int main(void)
{
	float miles, hours, minutes, gallons;
	char answer = 'y'; //answer to continue y or n

	while (answer == 'y') {
		std::cout << "Aircraft Fuel Calculator\n" << std::endl;

		std::cout << "Distance in nautical miles: ";
		std::cin >> miles;

		hours = static_cast<int>(miles) / static_cast<int>(miles_per_hour);

		//must multiply by 60 minutes in an hour
		minutes = (static_cast<int>(miles) % static_cast<int>(miles_per_hour)) / miles_per_hour; 
		gallons = (hours + minutes + safety_fuel) * gallons_per_hour;

		std::cout << std::fixed << std::setprecision(0);
		std::cout << "Flight time: " << hours << " hour(s) and "
			<< (60 * minutes) << " minute(s)\n";
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "Required fuel: " << gallons << " gallons\n" << std::endl;

		std::cout << "Continue? (y/n): ";
		std::cin >> answer;
	}
	std::cout << "\nBye!" << std::endl;

	return 0;
}
