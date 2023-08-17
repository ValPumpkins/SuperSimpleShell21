#include "main.h"
#include <ctype.h>
/*
int is_whitespace(char *str)
{
    while (*str)
    {
        if (!isspace((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}
*/

/**
 * main - Shell
 * @ac: Number of arguments
 * @av: Arguments
 * Return: 0
*/
int main(void)
{
    int exe;
    char *input = NULL;
    char **args = NULL;
    size_t bufsize = 0;

    while (1)
    {
        fflush(stdout);

        if (getline(&input, &bufsize, stdin) == -1)
            break;

        if (*input == '\n')
            continue;

        args = tokenize(input);

        exe = execute(input);
        if (exe == -1)
            perror(args[0]);

        free_args(args);
    }

    free(input);
    return (0);
}
