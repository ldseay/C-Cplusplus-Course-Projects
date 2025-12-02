/*
Create a program that calculates the area of various shapes.
Specifications
    • Use a switch statement to determine which shape was selected by the user.
    • Here are the formulas you can use to calculate the areas of the shapes:
circle_area = 3.14159 * radius2
square_area = height2
rectangle_area = height * width
    • Assume that the user will enter valid data for the radius, length, and width.
*/

#include <stdio.h>

const double pi = 3.14159;

//helper functions
void circle(void);
void square(void);
void rectangle(void);

int main(void)
{
	int shape, is_valid_input;
	char clear_buffer;

	puts("AREA CALCULATOR\n1. Circle\n2. Square\n3. Rectangle\n");

	printf("Menu item: ");
	is_valid_input = scanf("%d", &shape);

	if ((is_valid_input != 1) || (shape < 1) || (shape > 3)) {
		puts("\nInvalid menu item!");
		return 1;
	}
	while ((clear_buffer = getchar()) != '\n' && clear_buffer != EOF);

	switch (shape) {
		case 1:
			circle();
			break;
		case 2:
			square();
			break;
		case 3:
			rectangle();
			break;
	}
	return 0;
}

void circle(void)
{
	double radius;

	printf("\nCIRCLE\nRadius: ");
	scanf("%lf", &radius);

	printf("Area:   %lf\n\nBye!\n", (pi * (radius * radius)));
}

void square(void)
{
	double height;

	printf("\nSQUARE\nHeight: ");
	scanf("%lf", &height);

	printf("Area:   %lf\n\nBye!\n", (height * height));
}

void rectangle(void)
{
	double height, width;
	
	printf("\nRECTANGLE\nHeight: ");
	scanf("%lf", &height);

	printf("Width:  ");
	scanf("%lf", &width);

	printf("Area:   %lf\n\nBye!\n", (height * width));
}
