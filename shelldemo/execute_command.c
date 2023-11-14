#include "mainHeader.h"
/**
 * execute_shell_command - Function that executes the command found on the shell.
 * @tokens - List of tokens submitted by the parsine functions
 * Return: returns if the token is NULL.
 */

void execute_shell_command(char **tokens)
{
    if (tokens[0] == NULL)
        return;
    if (strcmp(tokens[0], "cd") == 0)
    {
        if (chdir(tokens[1]) != 0)
        {
            perror("cd");
        }
    }
    else if (strcmp(tokens[0], "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("Fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            if (execvp(tokens[0], tokens) == -1)
            {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            int status;

            if (waitpid(pid, &status, 0) == -1)
            {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        }
    }
}
