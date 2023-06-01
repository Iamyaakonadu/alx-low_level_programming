#include "variadic_functions.h"
#include <stdarg.h>

/**
 *sum_them_all - it returns the sum of all its parameter
 *@n: the number of parameters passed to the function
 *@...: variable number of parameter to calculate the sum of
 *
 *Return: if n == 0 - 0 otherwise the sum of all parameter
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i, sum = 0;

	va_start(ap, n);

	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);

	va_end(ap);

	return (sum);
}
