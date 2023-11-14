#include "mainHeader.h"

/**
 * main - Entrance to the Program
 * Return: 0 on Program successful ending;
 */

int main(void)
{
    char *command;
    char **tokens;
    while (1)
    {
        int i;

        prompt_shell();
        command = read_shell_command();
        tokens = parse_shell_command(command);
        execute_shell_command(tokens);

        /**
         * Cleaning up
         */
        free(command);

        for (i = 0; tokens[i] != NULL; i++)
        {
            free(tokens[i]);
        }
        free(tokens);
    }

    return 0;
}
