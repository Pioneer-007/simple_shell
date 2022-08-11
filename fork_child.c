#include "main.h"

/**
 * fork_child - Creates a child in  order to execute another program.
 * @vars: A structure cointaining a array of pointers and a string.
 */
void fork_child(vars_t vars)
{
	pid_t id;
	int status, check;
	struct stat buf;
	char *tmp_command, *command;

	id = fork();
	if (id != 0)
		wait(&status);
	else
	{
		tmp_command = vars.array_tokens[0];
		command = path_finder(vars, vars.array_tokens[0]);
		if (command == NULL)
		{
			/* Looking for file in current directory */
			check = stat(tmp_command, &buf);
			if (check == -1)
			{
				error_printing(vars.argv[0], vars.counter, tmp_command);
				print_str(": not found", 0);

				exit(100);
			}
			/* file exist in cwd or has full path */
			command = tmp_command;
		}
		vars.array_tokens[0] = command;
		if (vars.array_tokens[0] != NULL)
		{
			if (execve(vars.array_tokens[0], vars.array_tokens, vars.env) == -1)
				exec_error(vars.argv[0], vars.counter, tmp_command);
		}
	}
}

/**
 * path_finder - Acts as an interface for functions that will be able
 * to find the full path of a program.
 * @command: A common command such as ls, echo, pwd, etc..
 * Return: On success a string with the full path of the program.
 * @vars: structure with variables.
 * oterwise returns NULL.
 */
char *path_finder(vars_t vars, char *command)
{
	char *str = "PATH";
	char *constructed;
	char **path_tokens;
	int index, i;
	char *directory;

	index = find_env_index(vars, str);
	path_tokens = tokenize_path(vars, index, str);
	if (path_tokens == NULL)
		return (NULL);

	directory = search_directories(path_tokens, command);
	if (directory == NULL)
	{
		for (i = 0; path_tokens[i] != NULL; i++)
			free(path_tokens[i]);
		free(path_tokens);
		return (NULL);
	}
	constructed = build_path(directory, command);
	if (constructed == NULL)
	{
		for (i = 0; path_tokens[i] != NULL; i++)
			free(path_tokens[i]);
		free(path_tokens);
		return (NULL);
	}
	for (i = 0; path_tokens[i] != NULL; i++)
		free(path_tokens[i]);
	free(path_tokens);
	return (constructed);
}

/**
 * find_env_index - Finds the index of an environmental variable.
 * @vars: structure with variables will be used
 * @str: Environmental variable that needs to be found.
 * Return: Upon success returns the inde of the environmental variale
 * otherwise returns -1.
 */
