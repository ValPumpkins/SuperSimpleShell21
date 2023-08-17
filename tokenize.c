#include "main.h"

char **tokenize(char *input)
{
    char *token;
    char **args = NULL;
    int argCount = 0;

    args = (char **)malloc(100 * sizeof(char *)); // Assuming a maximum of 100 arguments
    if (args == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    token = strtok(input, " \t\n");

    while (token != NULL)
    {
        args[argCount++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[argCount] = NULL; // Null-terminate the argument list

    return args;
}
