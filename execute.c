#include "main.h"

/**
* execute - Executes a command
* @command: command to execute
*
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
	else if (pid == 0) // Child process
	{
		args = tokenize(input);
		exe = execve(args[0], args, NULL);
		if (exe < 0)
			return (-1);

		exit(1);
	}
	else // Parent process
		wait(&status); // Wait for the child process to exit

	return (1);
}
