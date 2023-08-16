#ifndef MAIN_H_
#define MAIN_H_

/* Library */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* Prototypes*/

int main(int ac, char **av);
void executeCommand(const char *command);
void findFilePath(const char *filename);







#endif
