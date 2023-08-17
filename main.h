#ifndef MAIN_H_
#define MAIN_H_

/* Library */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Prototypes*/

int execute(char *input);
char *getEnv(char *input);
int isEmpty(const char *str);
char **tokenize(char *input);

#endif
