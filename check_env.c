#include "main.h"

/**
 * getEnv - get the full path of an executable
 * @input: the executable name
 * Return: the full path of the executable
*/
char *getEnv(char *input)
{
    int i, inputLen;
    char **args;
    char *filename, *pathEnv, *pathCopy, *token, *result;
    char fullPath[1024];

    inputLen = strlen(input);

    for (i = 1; i < inputLen; i++)
    {
        args = tokenize(input);
        filename = args[0];

        // Try to find the executable in the PATH
        pathEnv = getenv("PATH");
        if (!pathEnv)
            return (NULL);

        pathCopy = strdup(pathEnv);
        token = strtok(pathCopy, ":");

        while (token)
        {
            snprintf(fullPath, sizeof(fullPath), "%s/%s", token, filename);

            if (access(fullPath, F_OK | X_OK) == 0)
            {
                result = strdup(fullPath);
                free(pathCopy);
                return (result);
            }

            token = strtok(NULL, ":");
        }

        free(pathCopy);
    }
    return 0;
}
