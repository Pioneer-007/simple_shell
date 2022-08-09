#include "shell.h"

void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
void variable_replacement(char **args, int *exe_ret);

/**
 * free_args - Frees up memory taken by args.
 * @args: A null-terminated double pointer containing commands/arguments.
 * @front: A double pointer to the beginning of args.
 */
void free_args(char **args, char **front)
{
	size_t i;

	for (i = 0; args[i] || args[i + 1]; i++)
		free(args[i]);

	free(front);
}

/**
 * get_pid - Gets the current process ID.
 * Description: Opens the stat file, a space-delimited file containing
 *              information about the current process. The PID is the
 *              first word in the file. The function reads the PID into
 *              a buffer and replace the space at the end with a \0 byte.
 *
 * Return: The current process ID or NULL on failure.
 */
char *get_pid(void)
{
	size_t i = 0;
	char *buffer;
	ssize_t file;

	file = open("/proc/self/stat", O_RDONLY);
	if (file == -1)
	{
		perror("Cant read file");
		return (NULL);
	}
	buffer = malloc(120);
	if (!buffer)
	{
		close(file);
		return (NULL);
	}
	read(file, buffer, 120);
	while (buffer[i] != ' ')
		i++;
	buffer[i] = '\0';

	close(file);
	return (buffer);
}

/**
 * get_env_value - Gets the value corresponding to an environmental variable.
 * @beginning: The environmental variable to search for
 * @len: The length of the environmental variable to search for
 *
 * Return: If the variable is not found - an empty string
 *         Otherwise - the value of the environmental variable.
 *
 * Description: Variables are stored in the format VARIABLE=VALUE.
 */
char *get_env_value(char *beginning, int len)
{
	char **var_addr;
	char *replacement = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, beginning, len);
