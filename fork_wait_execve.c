#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - executes the command ls -l /tmp in 5 different child processes
*
* Return: 0 on success and 1 if fork fails
*/
int main(void)
{
	int nbChildprocess = 5; /* requested number of child processes */
	int i, status;
	pid_t childPid;

	for (i = 0; i < nbChildprocess; i++) /* loop to create 5 child processes */
	{
		childPid = fork(); /* create child process */

		if (childPid== -1) /* if fork fails*/
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (childPid == 0) /* if child process executes successfully */
		{
			printf("Child %d (PID: %d) executes ls -l /tmp:\n", i + 1, getpid()); /* print child process info */
			execlp("ls", "ls", "-l", "/tmp", (char *)NULL); /* execute ls -l /tmp */
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(childPid, &status, 0); /* wait for child process to finish */
	}
	return (0);
}
