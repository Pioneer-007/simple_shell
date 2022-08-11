#include "main.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(vars_t *vars))(vars_t *vars)
{
	unsigned int i;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{"cd", new_cd},
		{"help", new_help},


		{NULL, NULL}};

	for (i = 0; check[i].f != NULL; i++)
	{
		/** vars->array_tokens esta accediendo a los argumentos para el match */
		if (_strcmpr(vars->array_tokens[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
		check[i].f(vars);
	return (check[i].f);
}

/**
 * new_exit - exit program
 * @vars: variables
 * Return: void
 */
void new_exit(vars_t *vars)
{

	int status;
	/*Si exit tiene argumentos, lo manejamos/
	if (_strcmpr(vars->array_tokens[0], "exit") ==
			0 &&
		vars->array_tokens[1] != NULL)

	{
		/* con esta funcion nos aseguramos que el numero ingresado sea valido*/
		status = _atoi(vars->array_tokens[1]);
		/* manejamos caso de error*/
		if (status == -1)
		{
			vars->status = 2;
			/*imprimira un mensaje de error */
			prints_error_msg(vars, ": Illegal number: ");
			print_message(vars->array_tokens[1]);
			print_message("\n");
			return;
		}
		vars->status = status;
	}
	free(vars->commands);
	free(vars->array_tokens);


	free_env(vars->env);
	free(vars->buffer);
	exit(vars->status);
}

/**
 * _env - prints the current environment
 * @vars: struct of variables
 * Return: void.
 */
void _env(vars_t *vars)
{
	unsigned int i;

	for (i = 0; vars->env[i]; i++)
	{
		_puts(vars->env[i]);
		_puts("\n");
	}
	vars->status = 0;
}
