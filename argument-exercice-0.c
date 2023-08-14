#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
	argv++;

	while (*argv != NULL)
	{
		printf("%s\n", *argv);
		argv++;
	}

	return (0);
}
