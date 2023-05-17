#include <stdlib.h>
#include "main.h"

/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '0'))
			count++;
	}
	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, n = 0;

	if (str == NULL || str[0] == '0')
			return (NULL);

			n = count_words(str);
			words = malloc((n + 1) * sizeof(char *));
			if (words == NULL)
			return (NULL);

			for (i = 0; i < n; i++)
			{
			while (*str == ' ')
			str++;

			for (j = 0; str[j] && str[j] != ' '; j++)
			words[i] = malloc((j + 1) * sizeof(char));
			if (words[i] == NULL)
			{
			for (k = 0; k < i; k++)
			free(words[k]);
			free(words);
			return (NULL);
			}

			for (j = 0; str[j] && str[j] != ' '; j++)
				words[i][j] = str[j];
			words[i][j] = '0';
			str += j;
			}
	words[i] = NULL;
	return (words);
}
