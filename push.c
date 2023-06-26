#include "monty.h"
/**
 * _push - function that check if arg_n is 0 - 9 and push to the stack
 * @stack: a pointer to the top of the stack
 * @line_number: the line number
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (gl_var.arg_n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(gl_var.fd);
		free_dlistint(*stack);
		free(gl_var.arg_n);
		free(gl_var.cmd);
		exit(EXIT_FAILURE);
	}
	if (gl_var.arg_n[i] == '-')
	{
		i++;
	}
	if (gl_var.arg_n[i] > 57 || gl_var.arg_n[i] < 48)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(gl_var.fd);
		free_dlistint(*stack);
		free(gl_var.arg_n);
		free(gl_var.cmd);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, atoi(gl_var.arg_n));
}
