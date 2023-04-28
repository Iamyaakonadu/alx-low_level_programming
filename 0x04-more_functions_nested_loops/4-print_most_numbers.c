#include "main.h"

/**
  *print_most_numbers - Prints the numbers from 0 to 9
  *Description: Do not print 2 and 4
  *Return: The numbers from 0 up to 9
  */

void print_most_numbers(void)

{

	int m = 0;

	for (m = 0; m <= 9; m++)
	{
		if (m == 2 || m == 4)
		{
			continue;
		}
		else
		{
			_putchar(m + '0');
		}
	}
	_putchar('\n');
}
