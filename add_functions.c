#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if strings match. -1 Otherwise.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) != _strlen(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * error_printing - Prints a message error when a comand is not found.
 * @count: A counter keeping track of the number of commands run on the shell.
 * @av: The name of the program running the shell.
 * @command: The specific command not being found.
 */
void error_printing(char *av, int count, char *command)
