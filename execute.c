#include "main.h"

/**
 * execute - Executes a command
 * @input: The command to execute
 * Return: 1 on success, -1 on failure
*/
int execute(char *input)
{
	int status, exe;
	char **args;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		args = tokenize(input);
		exe = execve(args[0], args, NULL);
		if (exe < 0)
			return (-1);

		exit(1);
	}
	else
		wait(&status);

	return (1);
}
