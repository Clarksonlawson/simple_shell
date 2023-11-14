#include "mainHeader.h"
/**
 * read_shell_command - Function to read the command on the shell prompt
 * Return: Returns a list of command found on the stdin and ready for tokenization
 */
char *read_shell_command()
{
    char *command = malloc(BUFFER_SIZE * sizeof(char *));

    if (fgets(command, BUFFER_SIZE, stdin) == NULL)
    {
        perror("Error: command failed to read");
        exit(EXIT_FAILURE);
    }

    return command;
}
