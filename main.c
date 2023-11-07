#include "main.h"

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	Prompt();
	while (1)
	{
		char input[MAX_INPUT_SIZE];

		char *args[MAX_ARGS + 1];

		Input(input, MAX_INPUT_SIZE);

		if (strlen(input) == 0)
			continue;

		if (strcmp(input, "exit") == 0)
			exit(EXIT_SUCCESS);

		tokenizeInput(input, args);
		exeCommand(args);
	}

	return (0);
}

