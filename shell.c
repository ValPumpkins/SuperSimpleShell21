#include "main.h"

/**
* main - Entry point
* @ac: argument count
* @av: argument vector
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	char *prompt = "Shell 🎈";
	char *line = NULL;
	int exe;
	size_t len = 0;

	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);

		if (getline(&line, &len, stdin) == -1)
		{
			printf("Exiting...\n");
			break;
		}
		if (*line == '\n')
			continue;

		exe = execute(line);

		if (exe == -1)
			perror(argv[0]);
	}
	free(line);

	return (0);
}
