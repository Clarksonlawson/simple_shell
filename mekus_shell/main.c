#include "mainHeader.h"
/**
 * main - Entry point to the shell program
 * @argc: Argument count from command line
 * @argv: Array of arguments from commandline
 * @envp: Environmental variables of process
 * Return: 0 on program success and none zero number on error
 */

int main(int argc, char *argv[], char *envp[])
{

	char *shell_tokens;
	(void) *envp;

	while (1)
	{
		mekus_shell_prompt();
		shell_tokens = read_shell_command(argc, *argv);
		execute_shell_command(shell_tokens);
	}
	return (0);
}
