#include "monty.h"
/**
 * _div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: a pointer to the stack top
 * @line_number: the opcode file line
 */
void _div(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_dlistint(*stack);
		fclose(gl_var.fd);
		free(gl_var.arg_n);
		free(gl_var.cmd);
		exit(EXIT_FAILURE);
	}
	read = *stack;
	if (read->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		read = *stack;
		i = read->n;
		y = read->next->n;
		i = y / i;
		read->next->n = i;
		*stack = read->next;
		free(read);
	}
}
