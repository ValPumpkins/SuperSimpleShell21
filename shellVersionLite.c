#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
* main - run commands with their full path
*		after compil, type : /bin/ls
* Return: 0
*/
int main(void)
{
	char *prompt = "SuperSimpleShell 🎈 ";
	char *command  = NULL;
	pid_t pid;
	ssize_t read;
	size_t len = 0;

	while (1)
	{
		printf("%s", prompt);

		read = getline(&command, &len, stdin);

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
		if (command[read - 1] == '\n')
			command[read - 1] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execlp(command, command, (char *)NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}
