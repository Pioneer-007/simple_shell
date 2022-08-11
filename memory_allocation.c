#include "main.h"

/**
 * _realloc - reallocates a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to number of elements in the old array
 *
 * Return: pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t i;
