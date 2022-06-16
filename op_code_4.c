#include "monty.h"

void opcode_rotr(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;
	int i = 0;

	current = malloc(sizeof(stack_t));
	current = *h;
	original = *h;
	while(original->next != NULL)
		original = original->next;
	while (original != NULL)
	{
		current->n = original->n;
		current->prev = original->prev;
		current = current->next;
		original = original->prev;
	}
	*h = current;
	if (line_number)
		i++;
}
