#include "main.h"

/**
 * _puts_error - print a string to sdandart error
 * @str: string to print.
 * Return: void
 */

void _puts_error(char *str)
{
	long num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)

	{
		perror("fatal error");
		exit(100);
	}
}

/** imprime mensage de error con ciertor parametros **/
/**
 * prints_error_msg - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print
 *
 * Return: void
 */

void prints_error_msg(vars_t *vars, char *msg)
{
	char *count;

	_puts_error(vars->argv[0]);
	_puts_error(": ");

	/aqui croe una funcion para convertir un entero a string/
	count = integer_converter(vars->counter);
	_puts_error(count);
	free(count);
	_puts_error(": ");
	_puts_error(vars->array_tokens[0]);
	if (msg)
	{
		_puts_error(msg);
	}
	else
		perror("");
}

/**
 * integer_converter - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
