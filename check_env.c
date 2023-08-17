#include "main.h"

char *getEnv(char *input)
{
    char **args;

    for (int i = 1; i < strlen(input); i++)
    {
        args = tokenize(input);
        char *filename = args[0];

        // Try to find the executable in the PATH
        char *path_env = getenv("PATH");
        if (!path_env)
            return (NULL);

        char *path_copy = strdup(path_env);
        char *token = strtok(path_copy, ":");

        while (token)
        {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", token, filename);

            if (access(full_path, F_OK | X_OK) == 0)
            {
                char *result = strdup(full_path);
                free(path_copy);
                return result;
            }

            token = strtok(NULL, ":");
        }

        free(path_copy);
    }
    return 0;
}
