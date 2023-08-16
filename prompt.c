#include "main.h"


int main(int ac, char **av)
{
    (void)ac; (void)av;

    while (1)
    {
        printf("(MyShell)$ ");
        fflush(stdout);

        char *input = NULL;
        size_t bufsize = 0;

        if (getline(&input, &bufsize, stdin) == -1)
        {
            printf("Exiting...\n");
            free(input);
            break;
        }

        // Supprimer les caractères d'espacement en début de ligne
        char *trimmed_input = input;
        while (*trimmed_input && (*trimmed_input == ' ' || *trimmed_input == '\t'))
            trimmed_input++;

        //Vérifier si la ligne est vide après suppression des espacements
        if (*trimmed_input != '\n')
            execute(input);


        free(input);
    }
    return 0;
}
