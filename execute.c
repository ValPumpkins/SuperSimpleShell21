#include "main.h"

void execute(char *input)
{
    int status;

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) // Child process
    {
        // Split the input string into tokens using strtok
        char *token;
        char *args[100]; // Assuming a maximum of 100 arguments
        int argCount = 0;

        token = strtok(input, " \t\n"); // Split by space, tab, or newline

        while (token != NULL)
        {
            args[argCount++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[argCount] = NULL; // Null-terminate the argument list

        execve(args[0], args, NULL);

        perror("Execve failed"); // Print an error if execve fails
        exit(1);
    }
    else // Parent process
        wait(&status); // Wait for the child process to exit
}
