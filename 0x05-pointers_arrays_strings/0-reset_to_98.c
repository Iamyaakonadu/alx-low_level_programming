#include <stdio.h>

/**
 * reset_to_98 - updates the value of an integer to 98
 * @n: a pointer to an integer
 *
 * Return: void
 */

void reset_to_98(int *n)
{
	*n = 98;
}

/**
 * main - entry point
 *
 * Return: always 0
 */

int main(void)
{
	int num = 10;

	printf("Before reset: %dn", num);
	reset_o_98(&num);
	printf("After reset: %dn", num);

	return (0);
}
