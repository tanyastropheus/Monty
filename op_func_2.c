#include "monty.h"
/**
 * op_add - adds the top two elements of the stack
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
		err_msg('A', NULL, line_number);

	else
	{
		(*stack)->next->n = (*stack)->next->n + (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * op_nop - does not perform any action
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_nop(stack_t **stack, unsigned int line_number)
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
 * op_sub - subtracts the top element of the stack from the second top element
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack) /* if the stack is empty */
		err_msg('R', NULL, line_number);
	else
		printf("%d\n", (*stack)->n);
}

/**
 * op_div - divides the second top element of the stack by the top element
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack) /* if the stack is empty */
		err_msg('P', NULL, line_number);
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
 * op_mul - multiplies the second top element of the stack with the top element
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	int num_1, num_2;

	if (!*stack || !(*stack)->next)
		err_msg('S', NULL, line_number);
	else
	{
		num_1 = (*stack)->n;
		num_2 = (*stack)->next->n;
		(*stack)->n = num_2;
		(*stack)->next->n = num_1;
	}
}
