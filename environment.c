#include "main.h"

/**
 * make_enviroment - make the shell environment from the environment.
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */
char **make_enviroment(char **env)
{
char **newenviroment = NULL;

size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenviroment = malloc(sizeof(char *) * (i + 1));
	if (newenviroment == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenviroment[i] = _strdup(env[i]);
	newenviroment[i] = NULL;
	return (newenviroment);
}
