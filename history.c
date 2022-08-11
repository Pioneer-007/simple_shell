#include "main.h"

/**
 * *add_nodeint - Add node in the beginning
 * @head: The pointer of the history list.
 * @str: The string received.
 *
 * Return: On success 1
 */

void *add_nodeint(history_t **head, char *str)
{

	history_t *new = malloc(sizeof(history_t));
	history_t *copy = *head;

	if (!new)
	{
		free_listint(*head);
	}

	new->str = _strdup(str);
	if (new->str == NULL)
	{
		free_listint(*head);
	}

	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	copy = *head;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new;
	return (new);
}

/**
 * free_listint - free pointers related with malloc
 * @head: The pointer of the list
 *
 * Return: The number of elements in the list
 */

void free_listint(history_t *head)
{
	history_t *delete;

	if (!head)
		return;
	while (head)
	{
		delete = head->next;
		free(head->str);

		free(head);
		head = delete;
	}
	free(delete);
}

/**
 * new_history - Print the list of a single list
 * @vars: structure with variables.
 * Return: The number of elements in the list
 */

void new_history(vars_t *vars)
{
	history_t *tmp = vars->history;
	history_t *tmp2 = vars->history;
