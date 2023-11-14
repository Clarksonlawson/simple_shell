#include "mainHeader.h"
/**
 * read_command - Function to read the command on the shell prompt
 * Return: Returns a list of command found on the stdin and ready for tokenization
 */

char *read_shell_command()
{
	char *commandList = malloc(sizeof(char *) * BUFFER_SIZE);

	if(fgets(commandList, BUFFER_SIZE, stdin) == NULL)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	return (commandList);
}
