#include "main.h"
/**
 * print_shell_prompt - shows the shell prompt to user
 */

void print_shell_prompt(void)
{
	char *prompt = "CisFun$ ";

	write(1, prompt, strlen(prompt));
	fflush(stdout);
}
