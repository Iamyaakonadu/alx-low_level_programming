#include <stdio.h>
#include "main.h"

/**
  *_putchar - writes the character c to stdout
  *@c: the character to print
  *
  *return: on  success 1
  *On error, -1 is returned and errno is set appropriately.
  */

int _putchr(char c)
{
	return (write(1, &c, 1));
}
