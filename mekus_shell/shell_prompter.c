#include "mainHeader.h"
/**
 * mekus_shell_prompt - Function that displays the shell prompt to the user
 */

void mekus_shell_prompt(void)
{
	char *prompt_message = "Mekus $ ";

	write(1, prompt_message, strlen(prompt_message));
	fflush(stdout);
}
