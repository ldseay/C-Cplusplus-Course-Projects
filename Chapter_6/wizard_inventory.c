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
    • In another file, store the current items that the wizard is carrying. 
    • The wizard can only carry four items at a time.
    • For the drop command, display an error message if the user enters an invalid number for the item.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HOLD 4
#define TOTAL_ITEMS 10

//helper functions
int read_items(char* all_items[], int total, char* current_items[], int items);
void print_menu(void);
int walk(char* all_items[], int total, char* current_items[], int items);
void show(char* current_items[], int items);
int drop(char* current_items[], int items, int call_from_walk);
void save_game(char* current_items[], int items);
void free_memory(char* all_items[], int total, char* current_items[], int items);

int main(void) {
	//create char arrays to hold list of all items and current items
	char* all_items[TOTAL_ITEMS];
	char* current_items[MAX_HOLD] = {NULL};
	
	//seed random number
	srand(time(NULL));

	if (read_items(all_items, TOTAL_ITEMS, current_items, MAX_HOLD)) { //make sure read is successful
		printf("Error with read_items function call!\n");
		return 1;
	}
	//program intro
	printf("Wizard Inventory\n\n");
	print_menu();

	char user_choice; //stores command
	char buffer; //used to clear buffer
	char to_exit = 'c'; //continue until to_exit equals e
	
	while (to_exit != 'e') {
		printf("\nCommand: ");
		scanf("%c", &user_choice);
		while ((buffer = getchar()) != EOF && (buffer != '\n')); //clear input buffer
		switch (user_choice) {
			case 'w':
				walk(all_items, TOTAL_ITEMS, current_items, MAX_HOLD);
				break;
			case 's':
				show(current_items, MAX_HOLD);
				break;
			case 'd':
				drop(current_items, MAX_HOLD, 0);
				break;
			case 'p':
				print_menu();
				break;
			case 'e':
				to_exit = 'e';
				save_game(current_items, MAX_HOLD);
				break;
			default:
				printf("Invalid command!\n");
				break;
		}
	}	
	//free memory
	free_memory(all_items, TOTAL_ITEMS, current_items, MAX_HOLD);

	return 0;
}

int read_items(char* all_items[], int total, char* current_items[], int items)
{
	//open wizard_all_items.txt and store in all_items
	FILE* all_items_file;
	FILE* current_items_file;
	all_items_file = fopen("wizard_all_items.txt", "r");
	current_items_file = fopen("wizard_current_items.txt", "r");
	if (!all_items_file || !current_items_file) {
		perror("Error opening file:");
		return 1;
	}

	//use getline to read file POSIX only 
	char* line = NULL;
	size_t num = 0;
	ssize_t nread;
	int i = 0; //make sure all_items are not overflowed
	while ((nread = getline(&line, &num, all_items_file)) != -1 && i < total) {
		all_items[i] = malloc(nread + 1); //add 1 for '\0' byte
		if (!all_items[i]) {
			perror("Failed to allocate space:");
			free(line);
			fclose(all_items_file);
			fclose(current_items_file);
			return 2;
		}
		strcpy(all_items[i], line);
		i++;
	}
	free(line); //free getline malloc
	//read saved items
	char* item = NULL;
	size_t count = 0;
	ssize_t ncount;
	i = 0;
	while ((ncount = getline(&item, &count, current_items_file)) != -1 && i < items) {
		current_items[i] = malloc(ncount + 1);
		if (!current_items[i]) {
			perror("Failed to allocate space:");
			free(line);
			free(item);
			fclose(all_items_file);
			fclose(current_items_file);
			return 3;
		}
		strcpy(current_items[i], item);
		i++;
	}
	free(item);
	fclose(all_items_file);
	fclose(current_items_file);
	return 0;
}

void print_menu(void)
{
	printf("Command Menu\n(w)alk - Walk down the path\n(s)how - Show all items\n(d)rop - Drop an item\n(p)rint - Print command menu\n(e)xit - Exit program\n");
}

int walk(char* all_items[], int total, char* current_items[], int items)
{
	//generate random number
	int random_num = rand() % total;

	//print item found
	printf("While walking down the path, you see %s", all_items[random_num]);

	//get action
	char buffer;
	char to_grab;
	printf("Do you want to grab it? (y/n): ");
	scanf("%c", &to_grab);
	while ((buffer = getchar()) != EOF && buffer != '\n'); //clear input buffer
	
	//add item to current items
	if (to_grab == 'y') {
		for (int i = 0; i < items; i++) {
			if (current_items[i] == NULL) {
				//current_items[i] = all_items[random_num];
				current_items[i] = malloc(strlen(all_items[random_num]) + 1);
				strcpy(current_items[i], all_items[random_num]);
				return 0;
			}
		}
		//user must drop an item to grab new item
		char to_drop;
		printf("You can't carry any more items. Drop something first? (y/n): ");
		scanf("%c", &to_drop);
		while ((buffer = getchar()) != EOF && buffer != '\n');
		if (to_drop == 'y') {
			int d_item = drop(current_items, items, 1);
			//current_items[d_item] = all_items[random_num];
			current_items[d_item] = malloc(strlen(all_items[random_num]) + 1);
			strcpy(current_items[d_item], all_items[random_num]);
		}
	}
	return 0;
}

void show(char* current_items[], int items)
{
	int count = 1; //keep count of lines to print
	for (int i = 0; i < items; i++) {
		if (current_items[i]) {
			printf("%d. %s", count, current_items[i]);
			count++;
		}
	}
	if (count == 1) {
		printf("No items to display\n");
	}
}

int drop(char* current_items[], int items, int call_from_walk)
{
	//check to see if called from walk
	int drop_num;
	char buffer;

	if (call_from_walk) {
		printf("\n");
		show(current_items, items);
		printf("\nWhich number would you like to drop? ");
		//make sure number is valid
		char num_tested = 'n';
		while (num_tested == 'n') {
			scanf("%d", &drop_num);
			while((buffer = getchar()) != EOF && buffer != '\n');
			if (drop_num > items || drop_num < 1) {
				printf("Invalid number! Enter new number: ");
			} else {
				num_tested = 'y';
			}
		}
		//drop number and return to walk function
		free(current_items[drop_num - 1]);
		current_items[drop_num - 1] = NULL;
		return (drop_num - 1);
	} else {
		printf("Number: ");
		scanf("%d", &drop_num);
		while ((buffer = getchar()) != EOF && buffer != '\n');
		if (drop_num > items || drop_num < 1) {
			printf("Nothing to drop\n");
		} else {
			if (current_items[drop_num - 1] == NULL) {
				printf("Nothing to drop\n");
			} else {
				free(current_items[drop_num - 1]);
				for (int i = (drop_num - 1); i < items - 1; i++) {
					current_items[i] = current_items[i + 1];
				}
				current_items[items - 1] = NULL;
			}
		}
	}
	return 0;
}

void save_game(char* current_items[], int items)
{
	FILE* fp;
	fp = fopen("wizard_current_items.txt", "w");

	//write to file
	for (int i = 0; i < items; ++i) {
		if (current_items[i]) {
			fprintf(fp,"%s", current_items[i]);
		}
	}
	fclose(fp);
}

void free_memory(char* all_items[], int total, char* current_items[], int items)
{
	for (int i = 0; i < total; ++i) {
		free(all_items[i]);
		all_items[i] = NULL; //set to NULL to avoid dangling pointers
	}
	for (int i = 0; i < items; ++i) {
		if (current_items[i]) {
			free(current_items[i]);
			current_items[i] = NULL;
		}
	}
}

