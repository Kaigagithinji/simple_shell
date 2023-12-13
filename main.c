/**
 * File: main.c
 * Auth: Kaiga Githinji
 */

#include "shell.h"

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num1 = 5;
	int num2 = 10;
	int result;

	result = add_numbers(num1, num2);
	printf("The sum is: %d\n", result);

	return 0;
}

