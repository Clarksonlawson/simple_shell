#include "mainHeader.h"

/**
 * prompt_shell - Displays the shell prompts to the user;
 *
 */
void prompt_shell(void)
{
	char prompt[] = "CisFun $ ";

	write(1, prompt, strlen(prompt));
	fflush(stdout);
}
