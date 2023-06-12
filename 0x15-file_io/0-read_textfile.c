#include "main.h"
#include <stdlib.h>

/**
*read_textfile - it reads text file print to STDOUT
*@filename: the text file being read
*@letters: the number of letters to be read
*Return: the actual number of letters it could read and print,
*0 when function fails or filename is NULL
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *nice;
	ssize_t mn;
	ssize_t o;
	ssize_t p;

	mn = open(filename, O_RDONLY);
	if (mn == -1)
		return (0);
	nice = malloc(sizeof(char) * letters);
	p = read(mn, nice, letters);
	o = write(STDOUT_FILENO, nice, p);

	free(nice);
	close(mn);
	return (o);
}
