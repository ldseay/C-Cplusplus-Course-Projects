/*
Create a program that keeps track of the items that a wizard can carry.
Specifications
    • Your supplied with a file named wizard_all_items.txt that contains a list of all possible items that a wizard can carry. When the user selects the walk command, read these items from the file, randomly pick one, and give the user the option to grab it.
    	a wooden staff
	a scroll of invisibility
	a crossbow
	a scroll of uncursing
	a sword
	an unknown potion
	a potion of healing
	a tome of fire
	a tome of earth
	a tome of water
    • In another file, store the current items that the wizard is carrying. Make sure to update this file every time the user grabs or drops an item.
    • The wizard can only carry four items at a time.
    • For the drop command, display an error message if the user enters an invalid number for the item.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

#define MAX 10 //number of total items in wizard all items
#define MIN 4 //total number of items the wizard can carry

//helper functions
void starter(std::vector<std::string>& current_items, std::vector<std::string>& all_items);
void walk(std::vector<std::string>& all_items, std::vector<std::string>& current_items);
void show(std::vector<std::string>& current_items);
void drop(std::vector<std::string>& current_items);
void write_file(std::vector<std::string>& current_items);

int main(void) 
{
	//open input file
	std::ifstream input_file;
	input_file.open("wizard_all_items.txt");

	//read and store items from wizard_all_items.txt
	std::vector<std::string> all_items;
	std::string line;
	while (std::getline(input_file, line)) {
		all_items.push_back(line);
	}

	std::vector<std::string> current_items; //stores current items
	starter(current_items, all_items); //loads 3 random items
	
	//write header and command menu to terminal
	std::cout << "Wizard Inventory\n" << std::endl;
	std::cout << "COMMAND MENU\n"
		<< "walk - Walk down the path\n"
		<< "show - Show all items\n"
		<< "drop - Drop an item\n"
		<< "exit - Exit program\n" << std::endl;

	std::string user_ans; //store user command
	
	//main game while loop
	while (user_ans != "exit") {
		std::cout << "Command: ";
		std::cin >> user_ans;
		std::cout << std::endl;

		if (user_ans == "walk") {
			walk(all_items, current_items);
		} else if (user_ans == "show") {
			show(current_items);
		} else if (user_ans == "drop") {
			drop(current_items);
		}
	}
	std::cout << "Bye!" << std::endl;
	input_file.close();
	return 0;
}

void starter(std::vector<std::string>& current_items, std::vector<std::string>& all_items)
{
	//start out with three random items
	srand(time(nullptr));
	for (int i = 0; i < 3; i++) {
		int index = rand() % MAX;
		current_items.push_back(all_items[index]);
	}
	write_file(current_items);
}

void walk(std::vector<std::string>& all_items, std::vector<std::string>& current_items)
{
	srand(time(nullptr));
	int index = rand() % MAX;
	std::string found_item = all_items[index];
	char grab_item;
	char drop_item;

	//display found item
	std::cout << "While walking down a path, you see " << found_item << ".\n";
	std::cout << "Do you want to grab it? (y/n): ";
	std::cin >> grab_item;

	if ((grab_item == 'y') && (current_items.size() < 4)) {
		current_items.push_back(found_item);
		std::cout << "You picked up " << found_item << ".\n";
	} else if ((grab_item == 'y') && (current_items.size() == 4)) {
		std::cout << "You can't carry any more items. Drop something first.\n\n";
		show(current_items);
		std::cout << "Would you like to drop any item? (y/n): ";
		std::cin >> drop_item;
		if (drop_item == 'y') {
			drop(current_items);
			current_items.push_back(found_item);
			std::cout << "You picked up " << found_item << ".\n";
		} else {
			std::cout << "You did not pick up " << found_item << ".\n";
		}
	} else {
		std::cout << "You did not pick up " << found_item << ".\n";
	}
	//write to file
	write_file(current_items);

	std::cout << std::endl;
}
		

void show(std::vector<std::string>& current_items)
{
	for (size_t i = 0; i < current_items.size(); i++) {
		std::cout << (i + 1) << ". " << current_items[i] << std::endl;
	}
	std::cout << std::endl;
}

void drop(std::vector<std::string>& current_items)
{
	size_t number;
	std::cout << "Number to drop: ";
	std::cin >> number;
	bool is_valid = false;

	while (!is_valid) {
		if ((number - 1) > current_items.size()) {
			std::cout << "Invalid number\n";
			std::cout << "Try again: ";
			std::cin >> number;
		} else {
			is_valid = true;
		}
	}
	current_items.erase(current_items.begin() + (number - 1));
}

void write_file(std::vector<std::string>& current_items)
{
	std::ofstream output_file;
	output_file.open("wizard_current_items.txt");

	for (size_t i = 0; i < current_items.size(); i++) {
		output_file << current_items[i] << '\n';
	}
	output_file.close();
}
