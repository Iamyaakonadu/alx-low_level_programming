#include "main.h"
#include <unistd.h>
/**
  *_putchar - writes the character c to stdout
  *@c: zthe character to print
  *
  *Return: on success 1.
  *On error, -1is returned, and error is set appropriately.
  */
int_putchar(char)
{
	return (write(1, &c,1));
}
