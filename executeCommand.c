#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
