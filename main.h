#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int execute(char *input);
char *getEnv(char *input);
char **tokenize(char *input);
void free_args(char **args);

#endif
