#include "monty.h"
#include "lists.h"

data_t data = DATA_INIT;

/**
 * monty - a function to help main function
 * @argmt: a pointer to a list of arguments
 *
 * Description: opens and reads and calls the function
 * that will execute the corresponding function.
 */
void monty(args_t *argmt)
{
	size_t len = 0;
	int get = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (argmt->argnum != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.fptr = fopen(argmt->fnm, "r");
	if (!data.fptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, argmt->fnm);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		argmt->line_number++;
		get = getline(&(data.line), &len, data.fptr);
		if (get < 0)
			break;
		data.words = strtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			empty_all(0);
			continue;
		}
		code_func = get_func(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, argmt->line_number, data.words[0]);
			empty_all(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), argmt->line_number);
		empty_all(0);
	}
	empty_all(1);
}

/**
 * main - start of monty bytecode interpreter
 * @argcnt: number of arguments
 * @argarry: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argcnt, char *argarry[])
{
	args_t argmt;

	argmt.fnm = argarry[1];
	argmt.argnum = argcnt;
	argmt.line_number = 0;

	monty(&argmt);

	return (EXIT_SUCCESS);
}
