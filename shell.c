#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
void exe_command(char *command);
/**
 * main - Main function for the simple shell
 *
 * Return: 0 on success, otherwise a non-zero error code
 */

int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		printf("#cisfun$ ");

		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			printf("\n");
			break; /* Handle end of file (Ctrl+D) */
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		exe_command(buffer);
	}

	return (0);
}
/**
 * exe_command - Execute the given command in a child process
 * @command: The command to be executed
 *
 * Return: Nothing
 */
void exe_command(char *command)
{
	char *input = "#cisfun$ ";

	if (access(command, X_OK) == 0)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			/* Child process */
			execl(command, command, (char *)NULL);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("Error");
		}
		else
		{
			/* Parent process */
			wait(NULL);
		}
	}
	else
	{
		printf("%s: No such file or directory\n", input);
	}
}
