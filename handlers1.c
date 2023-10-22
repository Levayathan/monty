#include "monty.h"
#include "lists.h"
#include <stdio.h>
#include <unistd.h>

/**
 * pint_inst - pint handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pint_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *bgn = *stack;

	if (!bgn)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", bgn->n);
}

/**
 * pop_inst - pop handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pop_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	del_node_dll(stack, 0);
}

/**
 * swap_inst - swap handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void swap_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (dll_lenght(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	temp = find_node_dll(*stack, 0);
	num = temp->n;
	del_node_dll(stack, 0);
	node = put_node_dll(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		empty_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * add_inst - add handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void add_inst(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = find_node_dll(*stack, 0);
	stack_t *node_1 = find_node_dll(*stack, 1);

	if (dll_lenght(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	sum = node_0->n + node_1->n;
	del_node_dll(stack, 0);
	del_node_dll(stack, 0);
	node = node_begin(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		empty_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_inst - nop handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void nop_inst(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
