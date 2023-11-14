#include "mainHeader.h"
/**
 * parse_shell_command - A double pointer that takes in the array of commands
 * @command: Commands that are being sent for tokenization.
 * Return: Returns a list of tokens to be executed upon
 */
char **parse_shell_command(char *command)
{
	int count = 0;
	char **tokenList;
	char *shellToken;

	tokenList = malloc(sizeof(char *) * BUFFER_SIZE);
	if (tokenList == NULL)
	{
		perror("Memory Allocation failed\n");
		exit(EXIT_FAILURE);
	}
	shellToken = strtok(command, " \t\n\r");

	while (shellToken != NULL)
	{
		tokenList[count++] = strdup(shellToken);
		shellToken = strtok(NULL, " \t\n\r");
	}
	tokenList[count] = NULL;
	return (tokenList);
}
