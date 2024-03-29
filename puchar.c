#include "monty.h"
#include "lists.h"
#include <stdio.h>
#include <unistd.h>

/**
 * pchar_inst - pchar handler
 * @stack: double pointer to the stack wa gonna push to
 * @line_number: number of the line in the file
 */
void pchar_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		fprintf(stderr, PCHAR_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		fprintf(stderr, PCHAR_RANGE, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

/**
 * pstr_inst - pstr handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pstr_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}

	putchar('\n');
}
