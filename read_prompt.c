#include "main.h"
/**
 * read_shell_prompt - read shell command using getline
 * Return: -1 on failure and buffer on success
 */

char *read_shell_prompt()
{
	char *buffer = NULL;
	size_t bufferSize = 0;
	ssize_t count_chars;

	count_chars = getline(&buffer, &bufferSize, stdin);

	if (count_chars == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	return (buffer);
}
