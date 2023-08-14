#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * isSeparator - check if char is a separator from array
 * @c: given char
 * Return: true or false (1 or 0)
*/
int isSeparator(char c)
{
	char sep[] = " /"; // tableau de séparateurs
	int i;

	for (i = 0; sep[i] != '\0'; i++) // parcours du tableau
		if (c == sep[i]) // si le caractére est un séparateur
			return (1); // retourne 1

	return (0); // sinon retourne 0
}

/**
 * wordCount - count word len
 * @str: given string
 * Return: word len
*/
int wordCount(char *str)
{
	int i, count = 0;

	if (!str)
		return (0);

	for (i = 0; str[i] != '\0'; i++) // parcours de la chaine
		if (!isSeparator(str[i]) && (i == 0 || isSeparator(str[i - 1]))) // si le caractére n'est pas un séparateur
			count++; // incrémente le compteur

	return (count); // retourne le nombre de mots séparés
}

/**
 * strtow - seperate words
 * @str: given string
 * Return: new pointer to array
*/
char **strtow(char *str)
{
	char **words;
	/* sPos = str position - wPos = word position - aPos = array position*/
	int sPos, wPos, aPos = 0, count, wordLen, letterFound = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = malloc((wordCount(str) + 1) * sizeof(char *)); // alloue la mémoire pour le tableau
	if (words == NULL)
		return (NULL);

	for (sPos = 0; str[sPos] != '\0'; sPos++) // parcours de la chaine
	{
		if (!isSeparator(str[sPos]) && (sPos == 0 || isSeparator(str[sPos - 1]))) // si le caractére n'est pas un séparateur
		{
			wordLen = 0; // réinitialise le compteur de lettres dans le mot
			letterFound = 1; // si une lettre a été trouvée

			for (wPos = sPos; !isSeparator(str[wPos]) && str[wPos] != '\0'; wPos++) // parcours du mot
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
