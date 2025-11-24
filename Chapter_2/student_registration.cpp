/*
Create a program that allows a student to complete a registration form and displays a completion message that includes the user’s full name and a temporary password.
Specifications
    • The user’s full name consists of the user’s first name, a space, and the user’s last name.
    • The temporary password consists of the user’s first name, an asterisk (*), and the user’s birth year.
    • Assume the user will enter valid data.
*/

#include <iostream>
#include <string>

int main(void)
{
	//variables to store user input
	std::string f_name, l_name;
	int birth_year;

	std::cout << "Registration Form\n" << std::endl;

	std::cout << "First name: ";
	std::cin >> f_name;

	std::cout << "Last name: ";
	std::cin >> l_name;

	std::cout << "Birth year: ";
	std::cin >> birth_year;

	std::cout << "\nWelcome " << f_name << "!\n"
		<< "Your registration is complete." << std::endl;
	std::cout << "Name: " << f_name << ' ' << l_name << std::endl;
	std::cout << "Temporary password: " << f_name << '*' << birth_year << std::endl;

	return 0;
}
