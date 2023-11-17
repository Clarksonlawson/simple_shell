#include "mainHeader.h"
/**
 * read_shell_command - Function to read the command
 * Return: Returns a list of command found
 */
char *read_shell_command()
{
	char *commandTokens = malloc(BUFFER_SIZE * sizeof(char *));

	if (fgets(commandTokens, BUFFER_SIZE, stdin) == NULL)
	{
		perror("COmmand failed to read");
		exit(EXIT_FAILURE);
	}
	return (commandTokens);
}
