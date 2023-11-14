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

        shell_prompter();
        command = read_shell_command();
        tokens = parse_shell_command(command);
        execute_shell_command(tokens);

        cleanup(command, tokens);
    }

    return 0;
}
