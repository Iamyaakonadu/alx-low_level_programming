#include "main.h"

/**
*clear_bit - it set the value of a given bit to 0.
*@n: the pointerto the number to be changed
*@index: the index of the bit to clear
*
*Return: 1 if it worked, or -1 if an error occurred
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
