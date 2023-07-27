#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number where the add function is called.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	UNUSED(stack);

	if (arguments->stack_len < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n",
				line_number);
		free_all_arguments();
		exit(EXIT_FAILURE);
	}

	tmp1 = arguments->head;
	tmp2 = arguments->head->next;

	tmp2->n = tmp1->n + tmp2->n;
	delete_stack_node();

	arguments->stack_len -= 1;
}
