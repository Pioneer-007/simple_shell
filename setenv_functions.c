#include "main.h"

/**
 * add_value - create a new environment variable string
 * @key: variable name
 * @value: variable value
 *
 * Return: pointer to the new string;
 */

char *add_value(char *key, char *value)
{
	unsigned int len1, len2, i, j;
	char *new;

	len1 = _strlen(key);
	len2 = _strlen(value);
	new = malloc(sizeof(char) * (len1 + len2 + 2));
	if (new == NULL)
		return (NULL);
	for (i = 0; key[i] != '\0'; i++)
		new[i] = key[i];
	new[i] = '=';
	for (j = 0; value[j] != '\0'; j++)
		new[i + 1 + j] = value[j];
	new[i + 1 + j] = '\0';
	return (new);
}

/**
 * find_key - finds an environment variable
 * @env: array of environment variables
 * @key: environment variable to find
 *
 * Return: pointer to address of the environment variable
 */

char **find_key(char **env, char *key)
{
	unsigned int i, j, len;

	len = _strlen(key);
