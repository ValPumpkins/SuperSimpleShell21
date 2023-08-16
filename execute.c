#include "main.h"

int execute(char *input)
{
    int status, exe;

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

        exe = execve(args[0], args, NULL);

        // perror("error"); // Print an error if execve fails
        if (exe < 0)
            return (-1);

        exit(1);
    }
    else // Parent process
        wait(&status); // Wait for the child process to exit

    return (1);
}
