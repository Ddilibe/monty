#include "monty.h"

/**
 * opcode_swap - A function that swaps the teo top elements
 * @h: Pointer to the pointer to the head
 * @line_number: Line number in a file
 *
 * Return: No return
 */

void opcode_swap(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original, *previous;
	int w;

	w = count_stack(h);
	if (w > 2)
	{
		current = *h;
		while (current->next != NULL)
		{
			if (current->next->next->next == NULL)
			{
				previous = current;
				original = current->next;
				current = current->next->next;
				break;
			}
			current = current->next;
		}
		original->next = NULL;
		current->next = original;
		previous->next = current;
		original->prev = current;
		current->prev = previous;
	}
	else
	{
		printf("L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_nop - A function that does nothing
 * @h: Pointer to the pointer to the head
 * @line_number: Line number in a file
 *
 * Return: No return
 */

void opcode_nop(stack_t **h, unsigned int line_number)
{
	stack_t *current;

	if (line_number)
		current = *h;
	while (current != NULL)
		current = current->next;
}

void opcode_add(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;
	int w;

	w = count_stack(h);
	if (w > 2)
	{
		current = *h;

		while (current->next != NULL)
		{
			original = current;
			current = current->next;
		}
		original->n = current->n + original->n;
		original->next = NULL;
		free(current);
	}
	else
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}


void opcode_sub(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;
	int w;
	
	w = count_stack(h);
	if (w > 2)
	{
		current = *h;
		
		while (current->next != NULL)
		{
			original = current;
			current = current->next;
		}
		original->n = original->n - current->n;
		original->next = NULL;
		free(current);
	}
	else
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
