#include "monty.h"
/**
 * op_push - push an element on top of the stack made of a doubly linked list
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL) /* invalid pointer
			   * Is it necessary to test this for this project?
			   */
		return;

	new = create_new_node(line_number);

	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL) /* if the list is not empty */
		(*stack)->prev = new;
	*stack = new;
}

/**
 * op_pall - prints all the values on the stack, starting from the top.
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)(line_number);
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * op_pint - prints the value at the top of the stack, followed by a new line.
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack) /* if the stack is empty */
		err_message(ERR_PINT, NULL, line_number);
	else
		printf("%d\n", (*stack)->n);
}

/**
 * op_pop - removes the top element of the stack
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack) /* if the stack is empty */
		err_message(ERR_POP, NULL, line_number);
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack) /* if there is more than one element on stack */
			(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * op_swap - swaps the top two elements of the stack
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	int num_1, num_2;

	if (!*stack || !(*stack)->next)
		err_message(ERR_SWAP, NULL, line_number);
	else
	{
		num_1 = (*stack)->n;
		num_2 = (*stack)->next->n;
		(*stack)->n = num_2;
		(*stack)->next->n = num_1;
	}
}
