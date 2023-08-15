#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    // Obtenir le nombre total d'arguments passés à la ligne de commande, y compris le nom du programme
    int wordCount = argc;

    // Allouer un tableau de pointeurs de chaînes pour stocker les mots
    char **words = malloc(wordCount * sizeof(char *));

    // Vérifier si l'allocation de mémoire a réussi
    if (words == NULL)
	{
        perror("Memory allocation error"); // Afficher un message d'erreur
        return 1; // Quitter le programme avec un code d'erreur
    }

    // Parcourir les arguments passés en ligne de commande
    for (int i = 0; i < argc; i++)
        words[i] = argv[i]; // Copier l'argument dans le tableau de mots

    // Parcourir le tableau de mots et afficher chaque mot
    for (int i = 0; i < wordCount; i++)
        printf("%s\n", words[i]); // Afficher le mot

    // Libérer la mémoire allouée pour le tableau de mots
    free(words);

    return 0; // Indiquer que le programme s'est terminé avec succès
}
