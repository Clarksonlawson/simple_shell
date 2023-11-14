#include "mainHeader.h"

/**
 * main - Entrance to the Program
 * Return: 0 on Program successful ending;
 */

int main(void)
{
	char *shell_commands = NULL;
	char **tokens;

	while (1)
	{
		int i;

		prompt_shell();
		shell_commands = read_shell_command();
		tokens = parse_shell_command(shell_commands);
		execute_shell_command(tokens);

		/**
		 * Cleaning up the pointers
		 */
		free(shell_commands);
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
	return (0);
}
