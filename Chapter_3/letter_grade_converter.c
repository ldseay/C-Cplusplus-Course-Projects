/*
Create a program that converts number grades to letter grades.
Specifications
    • The grading criteria is as follows:
A    88-100
B    80-87
C    67-79
D    60-66
F     0-59
    • For grades less than 0, display a message that indicates that the numerical grade can’t be negative.
    • For grades greater than 100, display a message that indicates that the numerical grade is too large.
*/

#include <stdio.h>

//helper function
void get_letter_grade(int grade);

int main(void)
{
	int grade, is_valid_int;

	puts("Letter Grade Converter\n");

	printf("Enter numerical grade (1-100): ");
	is_valid_int = scanf("%d", &grade);

	if (is_valid_int != 1) {
		puts("Invalid input: must input a number between 0 and 100.\n");
		puts("Bye!");
	} else if (grade < 0) {
		puts("Numerical grade can't be negative.\n");
		puts("Bye!");
	} else if (grade > 100) {
		puts("Numerical grade is too large.\n");
		puts("Bye!");
	} else {
		get_letter_grade(grade);
	}
	return 0;
}

void get_letter_grade(int grade)
{
	char letter;

	if (grade >= 88) {
		letter = 'A';
	} else if (grade >= 80) {
		letter = 'B';
	} else if (grade >= 67) {
		letter = 'C';
	} else if (grade >= 60) {
		letter = 'D';
	} else {
		letter = 'F';
	}
	printf("Letter grade: %c\n\nBye!\n", letter);
}

