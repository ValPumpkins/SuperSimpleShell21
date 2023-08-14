#include <stdio.h>
#include <unistd.h>

/**
 * main - PID, PPID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid, my_ppid;

    my_pid = getpid(); // récupération du pid
	my_ppid = getppid(); // récupération du ppid

    printf("PID : %u\n", my_pid);
	printf("PPID : %u\n", my_ppid);
    return (0);
}
