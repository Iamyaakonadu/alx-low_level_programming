#include "main.h"

/**
*print_binary - it prints the equivalent binary of a decimal number
*@n: the number to print in binary
*/

void print_binary(unsigned long int n)
{
	int q, list = 0;
	unsigned long int present;

	for (q = 63; q >= 0; q--)
	{
		present = n >> q;

		if (present & 1)
		{
			_putchar('1');
			list++;
		}
		else if (list)
			_putchar('0');
	}
	if (!list)
		_putchar('0');
}
