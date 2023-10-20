#include "monty.h"
#include <string.h>

void empty_tokarray(void);
unsigned int tokarray_lenght(void);
int emp_line(char *line, char *delims);
void (*same_op(char *opcode))(stack_t**, unsigned int);
int initiate_monty(FILE *script_fd);

/**
 * empty_tokarray - Frees the global op_toks array of strings.
 */
void empty_tokarray(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * tokarray_lenght - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int tokarray_lenght(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * emp_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int emp_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * same_op - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*same_op(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", mon_submit},
		{"pall", mon_cover},
		{"pint", mon_desc},
		{"pop", mon_show},
		{"swap", mon_exchange},
		{"add", mon_plus},
		{"nop", mon_ref},
		{"sub", mon_min},
		{"div", mon_split},
		{"mul", mon_inc},
		{"mod", mon_type},
		{"pchar", mon_prtchr},
		{"pstr", mon_prtstr},
		{"rotl", mon_swapval},
		{"rotr", mon_oppswap},
		{"stack", mon_conv},
		{"queue", mon_oppconv},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * initiate_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int initiate_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (start_stck(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = split(line, DELIMS);
		if (op_toks == NULL)
		{
			if (emp_line(line, DELIMS))
				continue;
			empty_stck(&stack);
			return (prt_mall_err());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			empty_tokarray();
			continue;
		}
		op_func = same_op(op_toks[0]);
		if (op_func == NULL)
		{
			empty_stck(&stack);
			exit_status = inst_err(op_toks[0], line_number);
			empty_tokarray();
			break;
		}
		prev_tok_len = tokarray_lenght();
		op_func(&stack, line_number);
		if (tokarray_lenght() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			empty_tokarray();
			break;
		}
		empty_tokarray();
	}
	empty_stck(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (prt_mall_err());
	}

	free(line);
	return (exit_status);
}
