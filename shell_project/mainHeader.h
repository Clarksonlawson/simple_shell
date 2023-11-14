#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024

void shell_prompter();
char *read_Shell_command();
char **parse_shell_command(char *command);
void execute_shell_command(char **tokens);
void cleanup(char *command, char tokens);
#endif
