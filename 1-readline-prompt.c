#include <stdio.h>
#include <stdlib.h>

/**
 * main - application de prompt
 * Return: 0 si tout s'est bien passé
*/
int main(int ac, char **av)
{
    (void)ac; (void)av;

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        char *input = NULL;
        size_t bufsize = 0;

        if (getline(&input, &bufsize, stdin) == -1)
        {
            printf("Error : exiting...\n");
            free(input);
            break;
        }
        printf("You entered: %s", input);
        free(input);
    }
    return 0;
}
