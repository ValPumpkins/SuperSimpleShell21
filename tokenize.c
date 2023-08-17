#include "main.h"

/**
 * tokenize - tokenizes a string
 * @input: string to tokenize
 * Return: array of tokens
*/
char **tokenize(char *input)
{
	char *token;
	char **args = NULL;
	int argCount = 0;

	args = (char **)malloc(100 * sizeof(char *));
	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	token = strtok(input, " \t\n");

	while (token != NULL)
	{
		args[argCount++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;

	return (args);
}
