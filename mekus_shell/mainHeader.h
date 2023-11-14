#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
void mekus_shell_prompt();
char **read_shell_command(int argCount, char *args);
void execute_shell_command(char **command);

#endif
