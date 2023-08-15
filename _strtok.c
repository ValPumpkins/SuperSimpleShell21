#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_strtok(char *str, const char *delimiters)
{
    // Variable statique pour suivre la position dans la chaîne
    static char *nextToken = NULL;

    // Si une nouvelle chaîne est fournie, définissez la position au début de la nouvelle chaîne
    if (str != NULL)
        nextToken = str;
    // Si aucune nouvelle chaîne n'est fournie et qu'aucune position n'est enregistrée, retournez NULL
    else if (nextToken == NULL)
        return NULL;

    // Sauvegardez la position de début du jeton
    char *start = nextToken;

    // Ignorer les caractères de délimiteur en début de chaîne
    while (*nextToken != '\0' && strchr(delimiters, *nextToken) != NULL)
        nextToken++;

    // Si aucun autre caractère que les délimiteurs n'est trouvé, retournez NULL
    if (*nextToken == '\0')
    {
        nextToken = NULL; // Réinitialisez la position pour l'appel suivant
        return NULL;
    }

    // Trouvez la fin du jeton en recherchant le prochain caractère de délimiteur
    while (*nextToken != '\0' && strchr(delimiters, *nextToken) == NULL)
        nextToken++;

    // Si nous n'avons pas atteint la fin de la chaîne, terminez le jeton par un caractère nul
    if (*nextToken != '\0')
    {
        *nextToken = '\0'; // Terminez le jeton par un caractère nul
        nextToken++; // Passez au caractère suivant pour l'appel suivant
    }

    return start; // Retournez un pointeur vers le jeton trouvé
}
