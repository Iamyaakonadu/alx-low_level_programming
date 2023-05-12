#include "main.h"

/**
  *_isdigit - Checks for a digit, 0 through 9.
  *@c: The number to be checked
  *Reurn: 1 for character that will be a digit or 0 for otherwise
  */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
