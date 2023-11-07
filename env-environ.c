#include "main.h"
#include <stdlib.h>
#include <string.h>

char **local_environ;

/**
 * initializeEnviron - Initialize the local_environ array with environment variables.
 */
void initializeEnviron(void)
{
	extern char **environ;

	int env_count = 0;
	
	int i = 0;

	while (environ[env_count] != NULL)
	{
		env_count++;
	}

	local_environ = (char **)malloc((env_count + 1) * sizeof(char *));

	if (local_environ == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	for (i; i < env_count; i++)
	{
		local_environ[i] = strdup(environ[i]);
		if (local_environ[i] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
	}

	local_environ[env_count] = NULL;
}

