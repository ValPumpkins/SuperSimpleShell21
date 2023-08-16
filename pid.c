#include "main.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int pid(void)
{
    pid_t my_pid;

    my_pid = getpid(); // récupération du pid

    printf("PID : %u\n", my_pid);
    return (0);
}
