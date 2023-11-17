#include "main.h"
/**
 * main - The entry to the shell program
 * @argc: Argument count
 * @env: Evnironmental variable for shell
 * Return: 0 on success
 */

int main(int argc, char **env)
{
	
	char *commands;
	char **shell_tokens;
	(void)argc;
	

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_shell_prompt();
		}
		commands = read_shell_prompt();
		shell_tokens = tokenize_shell_inputs(commands);
		execute_shell_commands(shell_tokens, env);
	}
	free(commands);
	free(shell_tokens);
	return (0);
}

