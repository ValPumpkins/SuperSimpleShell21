#include <stdio.h>
#include <stdlib.h>

/**
 * main - afficher les arguments du programme
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return: 0 si tout va bien, 1 sinon
*/
int main(int argc, char ** argv)
{
	int i = 0;

	while (*argv != NULL) // tant que l'on peut avancer dans argv
	{
		printf("argv[%d]%s\n", i, *argv); // on imprime l'argument courant
		argv++; // on passe au prochain argument
		i++;
	}

	return (0);
}
