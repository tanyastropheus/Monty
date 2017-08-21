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
		err_message(ERR_ADD, NULL, line_number);

	else
	{
		(*stack)->next->n = (*stack)->next->n + (*stack)->n;
		op_pop(stack, line_number);
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
	(void)(stack);
	(void)(line_number);
}

/**
 * op_sub - subtracts the top element of the stack from the second top element
 * @stack: address to the pointer to the top of the stack, or the head node
 * @line_number: line number of the bytecode file
 * Return: Void
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
		err_message(ERR_SUB, NULL, line_number);

	else
	{
		(*stack)->next->n = (*stack)->next->n - (*stack)->n;
		op_pop(stack, line_number);
	}
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

	if (!*stack || !(*stack)->next)
		err_message(ERR_DIV, NULL, line_number);
	else if ((*stack)->n == 0)
		err_message(ERR_ZERO, NULL, line_number);
	else
	{
		(*stack)->next->n = (*stack)->next->n / (*stack)->n;
		op_pop(stack, line_number);
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
	stack_t *temp;

	if (!*stack || !(*stack)->next)
		err_message(ERR_MUL, NULL, line_number);
	else
	{
		(*stack)->next->n = (*stack)->next->n * (*stack)->n;
		op_pop(stack, line_number);
	}
}
