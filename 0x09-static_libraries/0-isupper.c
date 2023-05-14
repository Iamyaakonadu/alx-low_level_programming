#include "main.h"

/**
  *_isupper - Check if a letter is uppercase character.
  *@c: The number to be checked
  *Return: 1 for  uppercase letter or 0 for otherwise
  */

int _isupper(int c)
{

	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}
