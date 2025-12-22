/*
Create a program that reads the sales for 12 months from a file and calculates the total yearly sales as well as the average monthly sales.
Specifications
    • Your provided a tab-delimited file named monthly_sales.txt that contains the month and sales data shown here:
    Jan     14317.41        Feb     3903.32 Mar     1073.01 Apr     3463.28 May     2429.52 Jun     4324.70 Jul     9762.31 Aug     25578.39        Sep     2437.95 Oct     6735.63 Nov     288.11  Dec     2497.49

    • Round the results of the monthly average to a maximum of 2 decimal digits and make sure that a minimum of 2 decimal digits are displayed on the console.
    • Right-align the columns that display the monthly sales, the yearly total, and the monthly average.
*/

#include <stdio.h>
#include <stdlib.h>

#define MON 12
#define MON_LEN 5

//helper functions
void print_month(char month[MON][MON_LEN], float* sales);
void print_average(float* sales);

int main(void)
{
	char months[MON][MON_LEN] ;
	float sales[12];

	FILE* fp = fopen("monthly_sales.txt", "r");
	if (!fp) {
		perror("Error opening file: ");
		return 1;
	}

	for (int i = 0; i < MON; i++) {
		if (fscanf(fp, "%4s %f", months[i], &sales[i]) != 2) {
			perror("Error reading file: ");
			return 2;
		}
	}
	fclose(fp);

	char user_ans = 'a';

	puts("Monthly Sales\n");
	puts("COMMAND MENU\nm - View monthly sales\ny - View yearly summary\nx - Exit program");
	while (user_ans != 'x') {
		printf("\nCommand: ");
		scanf("%c", &user_ans);
		char clear_buffer;
		while ((clear_buffer = getchar()) != '\n' && clear_buffer != EOF);

		if (user_ans == 'm') {
			print_month(months, sales);
		} else if (user_ans == 'y') {
			print_average(sales);
		}
	}
	puts("\nBye!");
	return 0;
}

//prints month and sales for the month
void print_month(char month[MON][MON_LEN], float* sales)
{
	puts("\nMONTHLY SALES");

	for (int i = 0; i < MON; i++) {
		printf("%s\t%15.2f\n", month[i], sales[i]);
	}
}

//prints yearly summary of sales	
void print_average(float* sales)
{
	float total = 0;
	float average = 0;

	puts("\nYEARLY SUMMARY");

	for (int i = 0; i < MON; i++) {
		total = total + sales[i];
	}
	average = total / MON;
	printf("Yearly total:   \t%10.2f\n", total);
	printf("Monthly average:\t%10.2f\n", average);
}

