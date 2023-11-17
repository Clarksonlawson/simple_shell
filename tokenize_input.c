#include "main.h"
/**
 * tokenize_shell_inputs - break buffer into tokens
 * @shell_inputs: Inputs from buffer (stdin)
 * Return: command tokens on success
 */

char **tokenize_shell_inputs(char *shell_inputs)
{
	char **tokenList = malloc(sizeof(char) * 1024);
	int i, j;
	char *delim = " \n";

	i = 0;
	while (shell_inputs[i])
	{
		if (shell_inputs[i] == '\n')
		{
			shell_inputs[i] = 0;
		}
		i++;
	}

	j = 0;
	tokenList[j] = strtok(shell_inputs, delim);
	while (shell_inputs[j])
	{
		tokenList[++j] = strtok(NULL, delim);
	}
	return (tokenList);
}
