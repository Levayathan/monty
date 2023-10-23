#include "monty.h"
#include "lists.h"
#include <stdio.h>
#include <unistd.h>

/**
 * sub_inst - substraction handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void sub_inst(stack_t **stack, unsigned int line_number)
{
	int sub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = find_node_dll(*stack, 0);
	stack_t *node_1 = find_node_dll(*stack, 1);

	if (dll_lenght(*stack) < 2)
	{
		fprintf(stderr, SUB_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	del_node_dll(stack, 0);
	del_node_dll(stack, 0);
	node = node_begin(stack, sub);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAIL);
		empty_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_inst - division handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void div_inst(stack_t **stack, unsigned int line_number)
{
	int div = 0;
	stack_t *node = NULL;
	stack_t *node_0 = find_node_dll(*stack, 0);
	stack_t *node_1 = find_node_dll(*stack, 1);

	if (dll_lenght(*stack) < 2)
	{
		fprintf(stderr, DIV_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		fprintf(stderr, DIV_ZERO, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	div = node_1->n / node_0->n;
	del_node_dll(stack, 0);
	del_node_dll(stack, 0);
	node = node_begin(stack, div);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAIL);
		empty_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_inst - multiplication handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mul_inst(stack_t **stack, unsigned int line_number)
{
	int mul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = find_node_dll(*stack, 0);
	stack_t *node_1 = find_node_dll(*stack, 1);

	if (dll_lenght(*stack) < 2)
	{
		fprintf(stderr, MUL_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	del_node_dll(stack, 0);
	del_node_dll(stack, 0);
	node = node_begin(stack, mul);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAIL);
		empty_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_inst - mod handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mod_inst(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = find_node_dll(*stack, 0);
	stack_t *node_1 = find_node_dll(*stack, 1);

	if (dll_lenght(*stack) < 2)
	{
		fprintf(stderr, MOD_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		fprintf(stderr, DIV_ZERO, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	del_node_dll(stack, 0);
	del_node_dll(stack, 0);
	node = node_begin(stack, mod);
	if (!node)
	{
		fprintf(stderr, MALLOC_FAIL);
		empty_all(1);
		exit(EXIT_FAILURE);
	}
}
