#include "mainHeader.h"
/**
 * parse_shell_command - A double pointer that takes in the array of commands
 * @command - Commands that are being sent for tokenization.
 * Return: Returns a list of tokens to be executed upon
 */
char **parse_shell_command(char *command)
{
    int count = 0;
    char **tokenList;
    char *token;

    tokenList = malloc(sizeof(char *) * BUFFER_SIZE);
    if (tokenList == NULL)
    {
        perror("Error: Allocation of memory failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, " \t\n\r");

    while (token != NULL)
    {
        tokenList[count++] = strdup(token);
        token = strtok(NULL, " \t\n\r");
    }

    tokenList[count] = NULL;
    return tokenList;
}
