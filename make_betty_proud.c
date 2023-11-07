#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * executeCommand - Execute the given command in a child process
 * @command: The command to be executed
 *
 * Return: Nothing
 */
void executeCommand(char *command);

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;

	while (1)
	{
		printf("($) "); /* Display the shell prompt */
		getline(&input, &len, stdin);

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		executeCommand(input);
	}

	return (0);
}

/**
 * executeCommand - Execute the given command in a child process
 * @command: The command to be executed
 *
 * Return: Nothing
 */
void executeCommand(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error creating child process");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}

