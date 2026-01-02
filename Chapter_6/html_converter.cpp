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

#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
	std::string line; //stores lines from html file
	
	std::ifstream input_file;
	input_file.open("groceries.html");

	//output header line to console
	std::cout << "HTML Converter\n" << std::endl;

	while (std::getline(input_file, line)) {
		bool is_header_tag = line[1] == 'h' ? true : false;
		int index_first = (line.find('>')) + 1;
		int index_last = line.find('<', index_first);
		int len = index_last - index_first;
		if (index_last == -1) {
			continue;
		} else if (is_header_tag) {
			std::cout << line.substr(index_first, len) << std::endl;
		} else {
			std::cout << "* " << line.substr(index_first, len) << std::endl;
		}
	}
	input_file.close();
	return 0;
}
