#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * Prompt - Display the shell prompt
 *
 * Return: Nothing
 */
void Prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * Input - Get user input from stdin
 * @input: Buffer to store user input
 * @size: Size of the input buffer
 *
 * Return: Nothing
 */
void Input(char *input, size_t size)
{
	ssize_t read_size = read(STDIN_FILENO, input, size);

	if (read_size == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}

	input[strcspn(input, "\n")] = '\0';
}
/**
 * exeCommand - Execute the given command in a child process
 * @args: the command line argument
 * Return: Nothing
 */
void exeCommand(char *args[])
{
	extern char **environ;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error creating child process");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "./shell: %s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		waitpid(pid, NULL, 0);
	}
}
/**
 * tokenizeInput - Tokenize the input string into arguments.
 * @input: The input string to tokenize.
 * @args: An array to store the tokenized arguments.
 *
 * Return: Nothing.
 */
void tokenizeInput(char *input, char *args[])
{
	char *token = strtok(input, " ");

	int i = 0;

	while (token != NULL && i < MAX_ARGS)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL; /* Null-terminate the argument list */
}

