#include "main.h"


/** RETURNS A POINTER TO A NEW STRING ***/
/**
 * _strdup - returns pointer to new mem alloc space which contains copy
 * @strtodup: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *strtodup)
{
	char *copy;

		int len, i;

	if (strtodup == 0)
		return (0);

	for (len = 0; strtodup[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = strtodup[i];

return (copy);
}


/** COMPARES TWO STRINGS ***/
/**
 * _strcmpr - compares two strings
 * @strcmp1: first string, of two, to be compared in length
 * @strcmp2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
}


/** CONCATENATES TWO STRINGS **/
/**
 * _strcat - concatenates two strings
 * @strc1: first string
 * @strc2: second string
 * Return: pointer
 */
char *_strcat(char *strc1, char *strc2)
{
	char *newstring;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;
