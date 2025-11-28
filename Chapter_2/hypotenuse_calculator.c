/*
Create a program that calculates the hypotenuse of a right triangle after the user enters the lengths of the two short sides.
Specifications
    • Use the Pythagorean Theorem to calculate the length of the third side. The Pythagorean Theorem states that the square of the hypotenuse of a right-triangle is equal to the sum of the squares of the opposite sides:
    As a result, you can calculate side C like this:
	c = square_root(a2 + b2)
    • Side C should be rounded to a maximum of 3 decimal places.
*/

#include <stdio.h>

//helper function to calculate square root
double newton_sqrt(double n);

int main(void)
{
	//store sides
	double a, b, c;
	int is_valid_input = 1;
	int scanf_status;

	puts("Hypotenuse Calculator\n");

	while (is_valid_input) {
		printf("Side A: ");
		scanf_status = scanf("%lf", &a);

		if (scanf_status != 1) {
			while ((scanf_status = getchar()) != '\n' && scanf_status != EOF);
			puts("Invalid input, try again\n");
			continue;
		}
		printf("Side B: ");
		scanf_status = scanf("%lf", &b);

		if (scanf_status != 1) {
			while ((scanf_status = getchar()) != '\n' && scanf_status != EOF);
			puts("Invalid input, try again\n");
			continue;
		}
		is_valid_input = 0;
	}
	c = newton_sqrt((a*a) + (b*b));

	printf("Side C: %.3lf\n", c);
	return 0;
}

double newton_sqrt(double n)
{
	double x = n;
	double last = 0;

	while (x != last) {
		last = x;
		x = 0.5 * (x + (n / x));
	}
	return x;
}
