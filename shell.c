#include "main.h"

/**
* isEmpty - Checks if a string is empty
* @str: String to check
* Return: 1 if empty, 0 otherwise
*/
int isEmpty(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++) /** Iterate through the string */
	{
		if (str[i] != '\n')
		return (0); /** Not empty*/
	}
	return (1); /** Empty*/
}

/**
* main - Entry point
* @ac: argument count
* @av: argument vector
*
* Return: Always 0 (Success)
*/
int main(int ac, char **av)
{
	char *prompt = "SuperSimpleShell 🎈";
	char *line = NULL;
	ssize_t read;
	size_t len = 0;

	while (1)
	{
		printf("%s", prompt);

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (!feof(stdin))
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
			else
				break;
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (strcmp(line, "exit") == 0) /** Exit */
			break;

		if (!isEmpty(line))
			executeCommand(line);

		free(line);
	}

	return (0);
}
