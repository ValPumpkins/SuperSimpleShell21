#include "main.h"

int check_env(int argc, char **argv)
{
    // Vérifie si au moins un argument (autre que le nom du programme) est fourni
    if (argc < 2)
    {
        printf("Utilisation : %s nom_de_fichier ...\n", argv[0]);
        return 1;
    }

    // Parcours des arguments (noms de fichiers) fournis en ligne de commande
    for (int i = 1; i < argc; i++)
    {
        // Récupère le nom du fichier à chercher dans le PATH
        char *filename = argv[i];

        // Tente de trouver l'exécutable dans le PATH
        char *path_env = getenv("PATH");
        if (path_env != NULL)
        {
            // Duplique la variable d'environnement PATH pour la manipuler en toute sécurité
            char *path_copy = strdup(path_env);

            // Découpe le PATH en répertoires en utilisant ":" comme séparateur
            char *token = strtok(path_copy, ":");
            while (token != NULL)
            {
                // Construit le chemin complet du fichier en concaténant le répertoire et le nom de fichier
                char full_path[1024];
                snprintf(full_path, sizeof(full_path), "%s/%s", token, filename);

                // Vérifie si le fichier existe et est exécutable
                if (access(full_path, F_OK | X_OK) == 0)
                {
                    // Affiche le chemin complet si le fichier est trouvé et exécutable
                    printf("%s\n", full_path);
                    break;
                }

                // Passe au répertoire suivant dans le PATH
                token = strtok(NULL, ":");
            }

            // Libère la mémoire allouée pour la copie du PATH
            free(path_copy);
        }
    }

    return 0;
}
