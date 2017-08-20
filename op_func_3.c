#include "monty.h"
/**
 * op_mod - find the remainder of the 2nd top element of the stack divided by
 the top element
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
		err_message(ERR_MOD, NULL, line_number);
	else if ((*stack)->n == 0)
		err_message(ERR_ZERO, NULL, line_number);
	else
	{
		(*stack)->next->n = (*stack)->next->n / (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
