#include "main.h"

void free_args(char **args)
{
    int i;
    if (args)
    {
        for (i = 0; args[i] != NULL; i++)
            free(args[i]);

        free(args);
    }
}
