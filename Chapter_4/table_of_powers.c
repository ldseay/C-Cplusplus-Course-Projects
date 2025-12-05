/*
Create a program that displays a table of squares and cubes for the specified range of numbers.
Specifications
    • Use tabs to align the columns.
    • Assume that the user will enter valid integers.
    • Make sure the user enters a start integer that’s less than the stop integer. If the user enters a start integer that’s greater than the stop integer, display an error message and give the user a chance to enter the integers again.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int start, stop;
	long double squared, cubed;
	char is_valid_input = 'n';

	puts("Table of Powers");

	while (is_valid_input == 'n') {
		printf("\nEnter start number: ");
		scanf("%d", &start);
		getchar();

		printf("Enter stop number:  ");
		scanf("%d", &stop);
		getchar();

		if (start > stop) {
			puts("\nStart number must be less than stop number.");
			puts("Please try again.");
		} else {
			is_valid_input = 'y';
		}
	}
	puts("\nNumber  Squared Cubed");
	puts("======  ======= =====");

	for (int i = start; i <= stop; i++) {
		squared = powl(start, 2);
		cubed = powl(start, 3);

		printf("%d\t%.0Lf\t%.0Lf\n", start, squared, cubed);
		start++;
	}
	return 0;
}
