#include "main.h"

/**
*binary_to_uint - it converts abinary number to unsigned int
*@b: the string containing the binary number
*
*Return: the converted number, 0 if there is 1 or more chars in string b
*/

unsigned int binary_to_uint(const char *b)
{
	int s;
	unsigned int outcome = 0;

	if (!b)
		return (0);

	for (s = 0; b[s]; s++)
	{
		if (b[s] < '0' || b[s] > '1')
			return (0);
		outcome = 2 * outcome + (b[s] - '0');
	}
	return (outcome);
}
