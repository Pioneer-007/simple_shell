#ifndef SHELL_MAIN
#define SHELL_MAIN
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

/**
 * struct history - An structure for each command readed
 * @str: string
 * @counter: number of imputs
 * @next: Next element
 */

typedef struct history
{
	char *str;
	int counter;
	struct history *next;

} history_t;

/*fixing*/
/** Estructura con las posibles variables que vamos a usar **/
/**
 * struct variables - variables
 * @array_tokens: array of tokens(arguments)
  * @buffer: buffer of command
  * @status: to handle exit status
  * @argv: gets arguments at opening of shell
  * @counter: counts commands entered
  * @env: has enviroment
  * @commands: have commands.
  * @history: structure
  * @invert: structure
 */
typedef struct variables
{
	char **array_tokens;
	char *buffer;
	int status;
	char **argv;
	int counter;
	char **env;
	char **commands;
	history_t *history;
	history_t *invert;

} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

/***Some String operations and manipulation***/
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
ssize_t _puts(char *str);
int _strlen(char *str);
void print_str(char *str, int new_line);
int _write_char(char c);
int print_number(int n);
