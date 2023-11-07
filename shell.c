#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/* Function prototypes */
void Prompt(void);
void Input(char *input, size_t size);
void exeCommand(const char *command);

/**
 * main - Simple shell program
 *
 * Return: Always (0)
 */
int main(void)
{
	Prompt();
	while (1)
	{
		char input[MAX_INPUT_SIZE];

		Input(input, MAX_INPUT_SIZE);

		if (strlen(input) == 0)
			continue; /* Ignore input that are empty */

		if (strcmp(input, "exit") == 0)
			exit(EXIT_SUCCESS);

		exeCommand(input);
	}

	return (0);
}

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
 * @command: The command to be executed
 *
 * Return: Nothing
 */
void exeCommand(const char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error creating child process");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			fprintf(stderr, "./shell: %s: No such file or directory\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

