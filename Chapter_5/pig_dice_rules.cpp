/*
Create a program that reads a list of rules from a file and displays them.
Specifications
    • The text file named rules.txt is as follows:
    	Pig Dice Rules:
	* See how many turns it takes you to get to 20.
	* Turn ends when player rolls a 1 or chooses to hold.
	* If you roll a 1, you lose all points earned during the turn.
	* If you hold, you save all points earned during the turn.
    • The program should read all of the text from the rules.txt file and display it on the console.
*/

#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
	std::ifstream rules;
	std::string line;

	rules.open("rules.txt");
	
	while (getline(rules, line)) {
		std::cout << line << std::endl;
	}
	rules.close();

	return 0;
}
