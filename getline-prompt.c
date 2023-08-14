#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;      // Pointeur pour stocker la ligne entrée par l'utilisateur
    size_t len = 0;         // Variable pour stocker la longueur de la ligne
    ssize_t read;           // Variable pour stocker le nombre de caractères lus

    while (1) {             // Boucle infinie pour lire les commandes en continu
        printf("$ ");       // Affiche le prompt "$ "

        // Utilise la fonction getline pour lire une ligne de l'entrée standard (clavier)
        // Elle stocke la ligne dans le pointeur 'line' et sa longueur dans 'len'
        read = getline(&line, &len, stdin);

        if (read == -1) {   // Si la valeur retournée est -1, cela signifie la fin du fichier (Ctrl+D)
            break;          // Sort de la boucle
        }

        printf("%s", line); // Affiche la ligne (la commande saisie) sans l'exécuter
    }

    free(line);             // Libère la mémoire allouée pour la ligne
    return 0;               // Retourne 0 pour indiquer une exécution sans erreur
}
