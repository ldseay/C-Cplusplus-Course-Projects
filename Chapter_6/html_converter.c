/*
Create a program that reads an HTML file and converts it to plain text.
Specifications
    • Provided an HTML file named groceries.html that contains these HTML tags:
<h1>Grocery List</h1>
<ul>
    <li>Eggs</li>
    <li>Milk</li>
    <li>Butter</li>
</ul>
    • When the program starts, it should read the contents of the file, remove the HTML tags, remove any spaces to the left of the tags, add asterisks (*) before the list items, and display the content and the HTML tags on the console as shown above.
*/

#include <stdio.h>
#include <regex.h>

int main(void)
{
	char line[128]; //stores lines from the HTML file
	
	//open file
	FILE* fp = fopen("groceries.html", "r");

	if (!fp) {
		perror("Error opening file: ");
		return 1;
	}
	//set up regex patterns
	regex_t h1_line, li_line; //stores patterns for h1 and li lines
	regmatch_t match[2]; //stores match information from the regex patterns
	
	//get and store the patterns
	regcomp(&h1_line, "<h1>(.+)</h1>", REG_EXTENDED);
	regcomp(&li_line, "<li>(.+)</li>", REG_EXTENDED);

	puts("HTML Converter\n"); //output header line to terminal

	//read file and write output to terminal
	while (fgets(line, sizeof(line), fp)) {
		if ((regexec(&h1_line, line, 2, match, 0)) == 0) {
			int len = match[1].rm_eo - match[1].rm_so;
			printf("%.*s\n", len, (line + match[1].rm_so));
		} else if ((regexec(&li_line, line, 2, match, 0)) == 0) {
			int len = match[1].rm_eo - match[1].rm_so;
			printf("* %.*s\n", len, (line + match[1].rm_so));
		}
	}
	fclose(fp);
	return 0;
}
