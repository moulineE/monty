#include "monty.h"
/**
 * _pint - function that print the top stack
 * @stack: a pointer to the stack top
 * @line_number: not use here
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *read = *stack;
	(void)(line_number);

	if (read != NULL)
	{
		printf("%d\n", read->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
