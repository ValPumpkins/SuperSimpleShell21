#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf(":)"); // Print shell prompt

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
				break;
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		if (line[read - 1] == '\n') // Remove newline character from the end of the input
			line[read - 1] = '\0';

		printf("%s", line);

		if (*line != '\0')
			putchar('\n');
	}

	free(line);
	exit(EXIT_SUCCESS);
}
