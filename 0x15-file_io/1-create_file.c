#include "main.h"

/**
*create_file - it creates a file
*@filename: the pointer to the name of a file to be created
*@text_content: the pointer to a string to write to the file
*
*Return: if the file already exists, truncate it
*if filename is NULL return -1, if text_content is NULL create an empty file
*/
int create_file(const char *filename, char *text_content)
{
	int mn, o, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	mn = open(filename, O_CREAT | O_RDWR |
			O_TRUNC, 0600);
	o = write(mn, text_content, len);

	if (mn == -1 || o == -1)
		return (-1);
	close(mn);

	return (1);
}
