/*
Create a program that allows a student to complete a registration form and displays a completion message that includes the user’s full name and a temporary password.
Specifications
    • The user’s full name consists of the user’s first name, a space, and the user’s last name.
    • The temporary password consists of the user’s first name, an asterisk (*), and the user’s birth year.
    • Assume the user will enter valid data.
This code assumes a Unix/POSIX environment it uses the getline() function to read user input.
*/

#include <stdio.h>
#include <stdlib.h>

#define _GNU_SOURCE

int main(void)
{
	//variables to store user input
	char* f_name = NULL;
	size_t f_len = 0;
	char* l_name = NULL;
	size_t l_len = 0;
	ssize_t read;
	size_t birth_year;

	puts("Registration Form\n");

	printf("First name: ");
	read = getline(&f_name, &f_len, stdin);
	//check for getline error
	if (read == -1) {
		perror("getline()");
		free(f_name);
		return 1;
	}
	f_name[read - 1] = '\0';

	printf("Last name: ");
	read = getline(&l_name, &l_len, stdin);
	//check for getline error
	if (read == -1) {
		perror("getline()");
		free(f_name);
		free(l_name);
		return 1;
	}
	l_name[read - 1] = '\0';

	printf("Birth year: ");
	scanf("%d", &birth_year);

	printf("\nWelcome %s!\nYour registration is complete.\n", f_name);
	printf("Name: %s %s\n", f_name, l_name);
	printf("Temporary password: %s*%d\n", f_name, birth_year);

	free(f_name);
	free(l_name);

	return 0;
}
