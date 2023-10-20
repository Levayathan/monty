#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void empty_stck(stack_t **stack);
int start_stck(stack_t **stack);
int find_type(stack_t *stack);
void empty_tokarray(void);
unsigned int tokarray_lenght(void);
int initiate_monty(FILE *script_fd);
void last_tok_err(int error_code);

/* OPCODE FUNCTIONS */
void mon_submit(stack_t **stack, unsigned int line_number);
void mon_cover(stack_t **stack, unsigned int line_number);
void mon_desc(stack_t **stack, unsigned int line_number);
void mon_show(stack_t **stack, unsigned int line_number);
void mon_exchange(stack_t **stack, unsigned int line_number);
void mon_plus(stack_t **stack, unsigned int line_number);
void mon_ref(stack_t **stack, unsigned int line_number);
void mon_min(stack_t **stack, unsigned int line_number);
void mon_split(stack_t **stack, unsigned int line_number);
void mon_inc(stack_t **stack, unsigned int line_number);
void mon_type(stack_t **stack, unsigned int line_number);
void mon_prtchr(stack_t **stack, unsigned int line_number);
void mon_prtstr(stack_t **stack, unsigned int line_number);
void mon_swapval(stack_t **stack, unsigned int line_number);
void mon_oppswap(stack_t **stack, unsigned int line_number);
void mon_conv(stack_t **stack, unsigned int line_number);
void mon_oppconv(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **split(char *str, char *delims);
char *read_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int print_err(void);
int prt_mall_err(void);
int file_err(char *filename);
int inst_err(char *opcode, unsigned int line_number);
int inv_arg(unsigned int line_number);
int show_error(unsigned int line_number);
int desc_err(unsigned int line_number);
int sh_err(unsigned int line_number, char *op);
int spl_err(unsigned int line_number);
int prtchr_err(unsigned int line_number, char *message);

#endif /* __MONTY_H__ */
