#include "monty.h"

int sh_err(unsigned int line_number, char *op);
int spl_err(unsigned int line_number);
int show_error(unsigned int line_number);
int spl_err(unsigned int line_number);
int prtchr_err(unsigned int line_number, char *message);

/**
 * show_error - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int show_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * desc_err - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int desc_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * sh_err - Prints monty math function error messages
 *                     for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @op: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int sh_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * spl_err - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int spl_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * prtchr_err - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int prtchr_err(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
