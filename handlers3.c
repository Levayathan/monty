#include "monty.h"
#include "lists.h"

/**
 * rotl_inst - rotl handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotl_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = find_node_dll(*stack, 0);
	num = temp->n;
	del_node_dll(stack, 0);
	node_last(stack, num);
}

/**
 * rotr_inst - rotr handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void rotr_inst(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int num = 0, len = dll_lenght(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	temp = find_node_dll(*stack, len - 1);
	num = temp->n;
	del_node_dll(stack, len - 1);
	node_begin(stack, num);
}

/**
 * stack_inst - stack handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void stack_inst(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}


/**
 * queue_inst - queue handler
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void queue_inst(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}
