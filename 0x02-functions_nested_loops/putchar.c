#include <unistd.h>

int_putchar(char c)
{
	return write(1, &c, 1)
}
