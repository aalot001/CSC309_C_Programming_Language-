// billing_tool_theater.cpp : Defines the entry point for the console application.
/* Ahmed Alotaibi 

4 / 10 / 2017

C programming language
A billing tool for a movie theater. I used struct structure and have done the necessary implementations
to have valid values and made sure discount and tax included in the final result. */

#include "stdafx.h"
#include <stdlib.h>

double calculate(void);

struct Billing 

{	/*output variables */
	double price_adults,
		price_kids, price_seniors,
		discount,
		tax, price_total;

	/* input: price, number of adults/kids/seniors */
	int num_adults,
		num_kids,
		num_seniors,
		num_total;
	double price;
} tool;

double calculate(void)
{
	/* calculate the price of each part */

	tool.price_adults = tool.num_adults * tool.price;
	tool.price_kids = tool.num_kids * tool.price * 0.75;
	tool.price_seniors = tool.num_seniors * tool.price * 0.50;
	tool.price_total = tool.price_adults + tool.price_kids + tool.price_seniors;

	/* display total price for each */

	printf("\nTotal price of adult tickets: %.2f\n", tool.price_adults);
	printf("Total price of kids tickets: %.2f\n", tool.price_kids);
	printf("Total price of seniors tickets: %.2f\n", tool.price_seniors);
	printf("Grand total price: %.2f\n", tool.price_total);

	/* calculate discount */

	tool.num_total = tool.num_adults + tool.num_kids +
		tool.num_seniors;
	if (tool.num_total >= 30) {
		tool.discount = tool.price_total * 0.30;
	}
	else if (tool.num_total >= 20) {
		tool.discount = tool.price_total * 0.20;
	}
	else if (tool.num_total >= 10) {
		tool.discount = tool.price_total * 0.10;
	}
	else {
		tool.discount = 0;
	}
	printf("\nGroup discount money value: %.2f\n", tool.discount);

	/* calculate tax and final price */

	tool.price_total = tool.price_total - tool.discount;
	tool.tax = tool.price_total * 0.1;
	printf("Total price after discount: %.2f\n",
		tool.price_total);
	printf("Tax: %.2f\n",
		tool.tax);

	tool.price_total = tool.price_total + tool.tax;
	printf("Total price including tax: %.2f\n",
		tool.price_total);
	return 0.00;
}
int main() {

	while (1) {

		printf("Enter the regular price: ");
		scanf_s("%lf", &tool.price);
		printf("Enter the number of adults 14 or older: ");
		scanf_s("%d", &tool.num_adults);
		printf("Enter the number of kids under 14: ");
		scanf_s("%d", &tool.num_kids);
		printf("Enter the number of seniors above 65: ");
		scanf_s("%d", &tool.num_seniors);

		/* make sure all the input information are positive */
		tool.num_total = tool.price > 0,
			tool.num_adults > 0,
			tool.num_kids > 0,
			tool.num_seniors > 0;

		if (tool.price < 0
			|| tool.num_adults < 0
			|| tool.num_kids < 0
			|| tool.num_seniors < 0)

			printf("Error: the input values have to be "
				"greater than or equal to 0.\n");

		while (tool.num_total > 0) {
			calculate();
			return 0;

		}
	}
}
