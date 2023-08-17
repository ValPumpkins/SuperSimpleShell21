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
    unsigned int argCount = 0, i = 0;

    args = malloc(sizeof(char *));
    if (args == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    token = strtok(input, " \t\n");
    if (token == NULL)
    {
        free(args);
        exit(EXIT_FAILURE);
    }

    while (token != NULL)
    {
		args = realloc(args, i * sizeof(char *));
		if (args == NULL)
		{
			perror("Memory reallocation failed");
			exit(1);
		}
		i++;

        args[argCount++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    args[argCount] = NULL;

    return args;
}
