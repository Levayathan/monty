#include "monty.h"
#include "lists.h"

/**
 * word_cnt - count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int word_cnt(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
/**
 * **strtow - splits a string into words
 * @strg: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *strg)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(strg);
	words = word_cnt(strg);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(strg[i]) || strg[i] == '\0' || strg[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = strg[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * empty_everything - frees arrays of strings
 * @argmt: array of strings to free
 */
void empty_everything(char **argmt)
{
	int i;

	if (!argmt)
		return;

	for (i = 0; argmt[i]; i++)
		free(argmt[i]);

	free(argmt);
}
