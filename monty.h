#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * struct instruction_s - opcoode and its function
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

/**
 * struct global_s - variables set as global
 * @line: pointer to the buffer allocated by getline()
 * @stack: doubly linked list that serves as the stack
 * Description: global variables for all functions to access
 */
typedef struct global_s
{
	char *line; /* set getline buffer as global variable
		     * so that op_push function can run strtok to access operand
		     * need to be freed
		     */
	FILE *fptr;
	size_t *n;
	stack_t *stack;
} global_t;

extern global_t global;  /**
			  * this creates a prototype of the extern var, of the
			  * type global_t with the name "global
			  * since it's global, there is no need to create a ptr
			  * to the struct to pass b/w functions
			  */

/**
 * enum err_code - error code to print out appropriate error messages
 * @ERR_FILE: missing file or more than 1 file
 * @ERR_OPEN: file fails to open
 * @ERR_INVAL: opcode invalid
 * @ERR_INT: operand to push is not an integer
 * @ERR_MALLOC: malloc() failed
 * @ERR_PINT: stack empty when executing opcode pint
 * @ERR_POP: stack empty when executing opcode pop
 * @ERR_SWAP: less than two elements on stack when executing opcode swap
 * @ERR_ADD: less than two elements on stack when executing opcode add
 * @ERR_SUB: less than two elements on stack when executing opcode sub
 * @ERR_DIV: less than two elements on stack when executing opcode div
 * @ERR_ZERO: divided by 0 when executing opcode div/mod
 * @ERR_MUL: less than two elements on stack when executing opcode mul
 * @ERR_MOD: less than two elements on stack when executing opcode mod
 */

enum err_code
{
	ERR_FILE,
	ERR_OPEN,
	ERR_INVAL,
	ERR_INT,
	ERR_MALLOC,
	ERR_PINT,
	ERR_POP,
	ERR_SWAP,
	ERR_ADD,
	ERR_SUB,
	ERR_DIV,
	ERR_ZERO,
	ERR_MUL,
	ERR_MOD
};

void err_message(enum err_code code, char *spec, unsigned int line_number);
void (*get_op(char *s))(stack_t **stack, unsigned int line_number);
stack_t *create_new_node(unsigned int line_number);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
#endif /* MONTY_H */
