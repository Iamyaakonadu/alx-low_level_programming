#include "main.h"
/**
  *_islower-check if char is lowercase
  *@c: is the char to be checked
  *Return: (1) if char is lower, otherwise (0)
  */

int_islower(int c)
{
	if (c >= 'a' && c <= 'Z')
		return (1);
	else
		return (0);
}
