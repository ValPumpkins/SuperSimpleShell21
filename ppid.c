#include "main.h"

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int ppid(void)
{
    pid_t my_ppid;

	my_ppid = getppid(); // récupération du ppid

	printf("PPID : %u\n", my_ppid);
    return (0);
}
