#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int check_env(char *input)
{
    for (int i = 1; i < strlen(input); i++)
    {
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

        char *filename = args[0];

        // Try to find the executable in the PATH
        char *path_env = getenv("PATH");
        if (path_env != NULL)
        {
            char *path_copy = strdup(path_env);
            char *token = strtok(path_copy, ":");
            while (token != NULL)
            {
                char full_path[1024];
                snprintf(full_path, sizeof(full_path), "%s/%s", token, filename);

                if (access(full_path, F_OK | X_OK) == 0)
                {
                    printf("%s\n", full_path);
                    break;
                }

                token = strtok(NULL, ":");
            }
            free(path_copy);
        }
    }

    return 0;
}
