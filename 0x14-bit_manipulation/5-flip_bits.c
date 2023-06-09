#include "main.h"

/**
*flip_bits - it counts the number of bits to change
*to get fromone number to the other
*@n: the 1st number
*@m: the 2nd number.
*
*Return: number of the bits to change.
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int r, tally = 0;
	unsigned long int present;
	unsigned long int special = n ^ m;

	for (r = 63; r >= 0; r--)
	{
		present = special >> r;
		if (present & 1)
			tally++;
	}

	return (tally);
}
