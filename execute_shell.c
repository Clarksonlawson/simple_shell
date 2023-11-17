#include "main.h"
/**
 * execute_shell_commands - calls Execve on the shell tokens
 * @shell_tokens: Inputs from the buffers
 * @env: Shell envvironment
 */

void execute_shell_commands(char **shell_tokens, char **env)
{
	pid_t child_process;
	char *fileName;
	char *errorMsg;
	char newMessage[50];

	child_process = fork();
	if (child_process < 0)
	{
		perror("New Process Failed");
		exit(EXIT_FAILURE);
	}
	else if (child_process == 0)
	{
		if (execve(shell_tokens[0], shell_tokens, env) == -1)
		{
			fileName = shell_tokens[0];
			errorMsg = " :Command not found. ";
			strcpy(newMessage, fileName);
			strcat(newMessage, errorMsg);

			perror(newMessage);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(child_process, &status, 0) == -1)
		{
			perror("Main process failed");
			exit(EXIT_FAILURE);
		}
	}
}
