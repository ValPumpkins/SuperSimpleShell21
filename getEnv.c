#include "main.h"

/**
* getEnv - get the path of an executable
* @input: input string
* Return: path of the executable
*/
char *getEnv(char *input)
{
	char **args;
	char *filename, *pathEnv, *pathCopy, *token, *result;

	for (int i = 1; i < strlen(input); i++)
	{
		args = tokenize(input);
		filename = args[0];

		pathEnv = getenv("PATH");

		if (!pathEnv)
			return (NULL);

		pathCopy = strdup(pathEnv);
		token = strtok(pathCopy, ":");

		while (token)
		{
			char fullPath[1024];
			snprintf(fullPath, sizeof(fullPath), "%s/%s", token, filename);

			if (access(fullPath, F_OK | X_OK) == 0)
			{
				result = strdup(fullPath);
				free(pathCopy);
				return (result);
			}

			token = strtok(NULL, ":");
		}

		free(pathCopy);
	}
	return 0;
}
