#include "main.h"

/**
*get_endianness - it checks if a machine is little or big endian.
*Return: 0 if big endian, 1 if little endian.
*/

int get_endianness(void)
{
	unsigned int z = 1;
	char *x = (char *) &z;

	return (*x);
}
