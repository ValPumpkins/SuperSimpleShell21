#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * wordCount - count word len
 * @str: given string
 * Return: word len
*/
int wordCount(char *str, const char sep)
{
	int i, count = 0;

	if (!str)
		return (0);

	for (i = 0; str[i] != '\0'; i++) // parcours de la chaine
		if (str[i] != sep && (i == 0 || str[i - 1] == sep)) // si le caractére n'est pas un séparateur
			count++; // incrémente le compteur

	return (count); // retourne le nombre de mots séparés
}

/**
 * strtow - seperate words
 * @str: given string
 * Return: new pointer to array
*/
char **_strtok(char *str, const char sep)
{
	char **words;
	/* sPos = str position - wPos = word position - aPos = array position*/
	int sPos, wPos, aPos = 0, count, wordLen, letterFound = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = malloc((wordCount(str, sep) + 1) * sizeof(char *)); // alloue la mémoire pour le tableau
	if (words == NULL)
		return (NULL);

	for (sPos = 0; str[sPos] != '\0'; sPos++) // parcours de la chaine
	{
		if (str[sPos] != sep && (sPos == 0 || str[sPos - 1] == sep)) // si le caractére n'est pas un séparateur
		{
			wordLen = 0; // réinitialise le compteur de lettres dans le mot
			letterFound = 1; // si une lettre a été trouvée

			for (wPos = sPos; str[wPos] != sep && str[wPos] != '\0'; wPos++) // parcours du mot
				wordLen++; // incrémente le compteur de lettres dans le mot

			words[aPos] = malloc((wordLen + 1) * sizeof(char)); // alloue la mémoire pour le mot
			if (words[aPos] == NULL) // si le mot n'a pas pu âtre alloué
			{
				for (count = 0; count < aPos; count++) // parcours du tableau
					free(words[count]); // libération de la mémoire de chaque mot
				free(words); // libération de la mémoire du tableau
				return (NULL);
			}
			strncpy(words[aPos], &str[sPos], wordLen); // copie le mot dans le tableau
			words[aPos][wordLen] = '\0'; // ajoute le caractére de fin de chaine
			aPos++;	// on passe au caractére suivant
		}
	}
	if (letterFound == 0) // si aucune lettre a été trouvée
		return (NULL);

	words[aPos] = NULL; // ajoute le caractére de fin de tableau
	return (words); // retourne le tableau
}
