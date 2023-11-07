#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

/* Function prototypes */
void Prompt(void);
void Input(char *input, size_t size);
void exeCommand(char *args[]);
void tokenizeInput(char *input, char *args[]);
#endif /* MAIN_H */

