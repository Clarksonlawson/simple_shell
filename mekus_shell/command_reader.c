#include "mainHeader.h"
/**
 * read_shell_command - Function to read the shell command
 * @argCount: Number of arguments passed
 * @arguments: Array of arguments passed.
 * Return: Returns a command  pointer;
 */

char **read_shell_command(int argCount, char *arguments)
{
	char **_tokens = malloc(sizeof(char) * BUFFER_SIZE);
	int count;

	if (argCount == 0)
	{
		exit(EXIT_FAILURE);	
	}

	if (_tokens == NULL)
	{
		perror("Error: Memory Allocation failed\n");
		exit(EXIT_FAILURE);
	}

	for(count = 0; count < argCount; count++)
	{
		_tokens[count] = arguments[count];
	}
	return (_tokens);
}
