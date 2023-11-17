#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void print_shell_prompt(void);
char *read_shell_prompt();
char **tokenize_shell_inputs(char *shell_inputs);
void execute_shell_commands(char **shell_tokens, char **env);

#endif
