#include "mainHeader.h"
/**
 * execute_shell_command - Function to create a new process
 * @tokens: - Pointer to the list of commands
 * Return: Returns nothing on successful execution.
 */
void execute_shell_command(char **tokens)
{


	if (tokens[0] == NULL)
	{
		perror("Error: Command not found");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid_t newProcess = fork();

		if (newProcess == -1)
		{
			perror("New Process Failed");
			exit(EXIT_FAILURE);
		}
		else if (newProcess == 0)
		{
			if (execvp(tokens[0], tokens) == -1)
			{
				perror("Program Execution failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			if (waitpid(newProcess, &status, 0) == -1)
			{
				perror("Parent process Failed to wait");
				exit(EXIT_FAILURE);
			}
		}
	}
