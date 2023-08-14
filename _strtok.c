#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * isSeparator - check if char is a separator from array
 * @c: given char
 * Return: true or false (1 or 0)
*/
int isSeparator(char c)
{
	char sep[] = " /";
	int i;

	for (i = 0; sep[i] != '\0'; i++)
		if (c == sep[i])
			return (1);

	return (0);
}

/**
 * wordCount - count word len
 * @str: given string
 * Return: word len
*/
int wordCount(char *str)
{
	int i, count = 0;

	if (!str)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
		if (!isSeparator(str[i]) && (i == 0 || isSeparator(str[i - 1])))
			count++;

	return (count);
}

/**
 * strtow - seperate words
 * @str: given string
 * Return: new pointer to array
*/
char **strtow(char *str)
{
	char **words;
	/* sPos = str position - wPos = word position - aPos = array position*/
	int sPos, wPos, aPos = 0, count, wordLen, letterFound = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = malloc((wordCount(str) + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (sPos = 0; str[sPos] != '\0'; sPos++)
	{
		if (!isSeparator(str[sPos]) && (sPos == 0 || isSeparator(str[sPos - 1])))
		{
			wordLen = 0;
			letterFound = 1;

			for (wPos = sPos; !isSeparator(str[wPos]) && str[wPos] != '\0'; wPos++)
				wordLen++;

			words[aPos] = malloc((wordLen + 1) * sizeof(char));
			if (words[aPos] == NULL)
			{
				for (count = 0; count < aPos; count++)
					free(words[count]);
				free(words);
				return (NULL);
			}
			strncpy(words[aPos], &str[sPos], wordLen);
			words[aPos][wordLen] = '\0';
			aPos++;
		}
	}
	if (letterFound == 0)
		return (NULL);

	words[aPos] = NULL;
	return (words);
}
