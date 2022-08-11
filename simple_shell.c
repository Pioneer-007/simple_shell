#include "main.h"

/**
 * sig_handler - handles ^C signal interupt
 * @unused: unused variable (required for signal function prototype)
 *
 * Return: void
 */
static void sig_handler(int unused)
{
	(void)unused;
	if (sig_flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}
/**
 * main - main function for the shell
 * @argc: number of arguments passed to main, unused
 * @argv: array of arguments passed to main
 * @environment: array of environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc _attribute_((unused)), char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int i;
	unsigned int is_pipe = 0;

	vars_t vars = {NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL};

	vars.argv = argv;
	vars.env = make_enviroment(environment);
