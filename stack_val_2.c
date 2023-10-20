#include "monty.h"

void mon_plus(stack_t **stack, unsigned int line_number);
void mon_min(stack_t **stack, unsigned int line_number);
void mon_split(stack_t **stack, unsigned int line_number);
void mon_inc(stack_t **stack, unsigned int line_number);
void mon_type(stack_t **stack, unsigned int line_number);

/**
 * mon_plus - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void mon_plus(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		last_tok_err(sh_err(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	mon_show(stack, line_number);
}

/**
 * mon_min - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mon_min(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		last_tok_err(sh_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	mon_show(stack, line_number);
}

/**
 * mon_split - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mon_split(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		last_tok_err(sh_err(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		last_tok_err(spl_err(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	mon_show(stack, line_number);
}

/**
 * mon_inc - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mon_inc(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		last_tok_err(sh_err(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	mon_show(stack, line_number);
}

/**
 * mon_type - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mon_type(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		last_tok_err(sh_err(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		last_tok_err(spl_err(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	mon_show(stack, line_number);
}
