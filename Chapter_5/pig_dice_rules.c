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

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fh = fopen("rules.txt", "r");

	if (fh == NULL) {
		perror("Error opening file");
		return 1;
	}

	char* line = NULL;
	size_t len = 0;
	ssize_t num_read = 0;

	while ((num_read = getline(&line, &len, fh) != -1)) {
		printf("%s", line);
	}
	
	if (ferror(fh)) {
		perror("Getline failed");
		free(line);
		return 2;
	}
	
	free(line);
	fclose(fh);
	return 0;
}


