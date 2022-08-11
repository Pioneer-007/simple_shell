#include "main.h"

/* PRINT WITOUTH USING PRINF AND ADDING NEWLINE AS NEEDED */
/**
 * print_str - Prints a string character by character.
 * @str: String to be printed. If the string is NULL it will print (null)
 * @new_line: If integer is 0 a new line will be printed. Otherwise a new line
 * will not be printed.
 */
void print_str(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);
	if (new_line == 0)
		write(STDOUT_FILENO, "\n", 1);
}

/* PRINT A SINGLE LETTER */
/**
 * _write_char - Writes a character to stdout
 * @c: Character that will be written to stdout
 * Return: Upon success how many characters were written.
 */
int _write_char(char c)
{
	return (write(1, &c, 1));
}
