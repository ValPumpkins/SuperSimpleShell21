#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *line = NULL;       // Pointeur pour stocker l'entrée de l'utilisateur
    size_t len = 0;          // Longueur de l'entrée
    ssize_t read;            // Nombre de caractères lus

    while (1) // Démarre une boucle infinie
    {
        printf("$ ");        // Affiche le prompt du shell

        // Lit l'entrée de l'utilisateur en utilisant getline
        read = getline(&line, &len, stdin);

        if (read == -1) // Vérifie si la fin du fichier ou une erreur s'est produite
        {
            if (feof(stdin))
            {
                // Si Ctrl+D (EOF) est détecté, sort de la boucle
                break;
            }
            else
            {
                perror("getline"); // Affiche un message d'erreur si getline a échoué
                exit(EXIT_FAILURE); // Quitte le programme avec un statut d'échec
            }
        }

        // Supprime le caractère de nouvelle ligne de la fin de l'entrée
        if (line[read - 1] == '\n')
        {
            line[read - 1] = '\0';
        }

        // Affiche l'entrée
        printf("%s", line);

        if (*line != '\0')
        {
            putchar('\n'); // Affiche un caractère de nouvelle ligne après l'entrée, si elle n'est pas vide
        }
    }

    free(line);              // Libère la mémoire allouée pour l'entrée
    exit(EXIT_SUCCESS);      // Quitte le programme avec un statut de succès
}
