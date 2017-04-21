// Temperature_Convertor.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<stdio.h>

/* Ahmed Alotaibi
2/1/2017
A program that asks users for integers and convert them
into a temperature dagree. It will keep asking until the right
input provides by the users. */


int main()
{
	int choice;
	float celsius, fahrenheit;

	while (1)
	{
		printf("|-----------------------------|\n"
			"|\tTemperature convertor | \n"
			"|---------------------------- |\n"
			"\n"
			"1.Convert from celsius to fahrenheit: \n"
			"2.Convert from fahrenheit to celsius: \n"
			"3.Exit\n"
			"-----------------------------\n"
			"What do you like to choice: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n\tEnter temperature to convert: ");
			scanf_s("%f", &celsius);
			if (celsius <= 50)
			{
				celsius = 9 * celsius / 5 + 32;
				printf("\tFrom degree in celsius to fahrenheit = F: %.2f \n", celsius);
			}
			else if (celsius > 50)
			{
				printf("\n\tValue should be equal or less than 50: \n\n");
			}
			break;
		case 2:
			printf("\n\tEnter temperature to convert: ");
			scanf_s("%f", &fahrenheit);
			if (fahrenheit <= 122)
			{
				fahrenheit = 5 * (fahrenheit - 32) / 9;
				printf("\tFrom dagree in fahrenheit to celsius = C: %.2f \n", fahrenheit);
			}
			else if (fahrenheit > 122)

			{
				printf("\n\tValue should be equal or less than 122: \n\n");
			}
			break;
		case 3:
			printf("\n");
			printf("Thanks for coming by \n");
			return 0;
			break;
		default:
			printf("\n");
			printf("\tPlease choice from the menu : \n");
			printf("\n");
		}
	}
	return 0;
}
