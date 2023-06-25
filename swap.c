#include "monty.h"
/**
 * _swap - function that swaps the top two elements of the stack.
 * @stack: a pointer to the stack top
 * @line_number: the opcode file line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *read = *stack;
	int i = 0;

	while (read != NULL)
	{
		i += 1;
		read = read->next;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		read = *stack;
		i = read->n;
		read->n = read->next->n;
		read->next->n = i;
	}
}
