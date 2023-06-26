#include "monty.h"

void execute(char *cmd, stack_t **stack, int line_number);
void _comment(stack_t **stack, unsigned int line_number);
/**
 * execute - function that select and execute the correct opreation
 * @cmd: the op code line
 * @stack: the stack top head
 * @line_number: the line number
 */
void execute(char *cmd, stack_t **stack, int line_number)
{
	unsigned int i = 0;
	char *op;
	instruction_t optf[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"#", _comment},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{NULL, NULL}
	};

	op = strtok(cmd, " \n\t");
	if (op[0] == '#')
	{
		return;
	}
	(gl_var.arg_n) = strtok(NULL, " \n\t");
	while ((optf[i].opcode != NULL) && (op != NULL))
	{
		if (strcmp(op, optf[i].opcode) == 0)
		{
			optf[i].f(stack, line_number);
			return;
		}
		i++;
	}
	if (optf[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(gl_var.fd);
		free(cmd);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
return;
}
/**
 * _comment - comment flag
 * @stack: a pointer to the stack top
 * @line_number: not use here
 */
void _comment(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	(void)(stack);
}
