#include "monty.h"
#include "lists.h"

/**
 * get_func - selects the right function
 * @parsed: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_inst},
		{"pall", pall_inst},
		{"pint", pint_inst},
		{"pop", pop_inst},
		{"swap", swap_inst},
		{"add", add_inst},
		{"nop", nop_inst},
		{"sub", sub_inst},
		{"div", div_inst},
		{"mul", mul_inst},
		{"mod", mod_inst},
		{"pchar", pchar_inst},
		{"pstr", pstr_inst},
		{"rotl", rotl_inst},
		{"rotr", rotr_inst},
		{"stack", stack_inst},
		{"queue", queue_inst},
		{NULL, NULL}
	};

	int codes = 17, i;

	for (i = 0; i < codes; i++)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

/**
 * push_inst - push handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void push_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, i;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		empty_all(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			empty_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = node_begin(stack, num);
	else if (data.qflag == 1)
		new = node_last(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		empty_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall_inst - pall handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void pall_inst(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dll(*stack);
}
