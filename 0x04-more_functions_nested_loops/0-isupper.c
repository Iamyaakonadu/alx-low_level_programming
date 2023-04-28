#include "main.h"

/**
  *_ispper - Check if a letter is uppercase character.
  *@x: The number to be checked
  *Return: 1 for  uppercase letter or 0 for otherwise
  */

int _isupper(int y)
{
	if (y >= 65 && y <= 90)
	{
		return (1);
	}
	return (0);
}
