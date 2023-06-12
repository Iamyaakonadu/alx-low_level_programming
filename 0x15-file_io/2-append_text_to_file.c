#include "main.h"

/**
*append_text_to_file - it appends text at the end of a file
*@filename: the pointer to the name of a file
*@text_content: the string to add the the end of the file
*
*Return:  1 on success and -1 on failure, If filename is NULL return -1
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int p, r, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	r = write(p, text_content, len);

	if (p == -1 || r == -1)
		return (-1);

	close(p);
	return (1);
}
