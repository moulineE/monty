#include "monty.h"

stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/**
 * add_dnodeint - function that adds a new node at the beginning
 * of a dlistint_t list.
 * @head: a pointer to the head of the list
 * @n: the data of the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *current = *head;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		exit(0);
	}
	new->n = n;
	new->next = current;
	new->prev = NULL;
	if (current != NULL)
	{
		current->prev = new;
	}
	*head = new;
	return (*head);
}

/**
 * free_dlistint -  function that frees a dlistint_t list.
 * @head: a pointer to the head of th list
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
