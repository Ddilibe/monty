#include "monty.h"

void opcode_rotr(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;
	int i = 0;

	current = malloc(sizeof(stack_t));
	if (current == NULL)
		exit(EXIT_FAILURE);
	original = *h;
	while(original->next != NULL)
		original = original->next;
	while (original != NULL)
	{	
		plain.e = original->n;
		printf("Rotr: %d, Plain.e: %d\n", original->n, plain.e);
		opcode_push(&current, original->n);
		original = original->prev;
	}
	*h = current;
	if (line_number)
		i++;
}
