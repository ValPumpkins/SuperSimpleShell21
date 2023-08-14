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
	argv++; // on skip le premier argument

	while (*argv != NULL) // tant que l'on peut avancer dans argv
	{
		printf("%s\n", *argv); // on imprime l'argument courant
		argv++; // on passe au prochain argument
	}

	return (0);
}
