#include "monty.h"
/**
 * _sub - function that subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: a pointer to the stack top
 * @line_number: the opcode file line
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *read = *stack;
	int i = 0, y;

	while (read != NULL)
	{
		i += 1;
		read = read->next;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		read = *stack;
		i = read->n;
		y = read->next->n;
		i = y - i;
		read->next->n = i;
		*stack = read->next;
		free(read);
	}
}
