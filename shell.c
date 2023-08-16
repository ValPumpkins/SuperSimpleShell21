#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
* executeCommand - Executes a command
* @command: command to execute
*
*/
void executeCommand(const char *command)
{
	pid_t pid = fork();

	if (pid == -1) /** Error */
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /** Child */
	{
		if (access(command, X_OK) == 0)  /** Check if the command exists */
		{
			execlp(command, command, (char *)NULL); /**Execute command using full path*/
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else /** if command is not excutable */
		{
			printf("%s\n", command); /** print input as text */
			exit(EXIT_SUCCESS);
		}
	}
	else
		waitpid(pid, NULL, 0); /** Wait for the child process to finish */
}

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
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
