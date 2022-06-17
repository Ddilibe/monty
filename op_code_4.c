#include "monty.h"

/**
 * opcode_rotr - A function that does nothing
 * @h: Pointer to the pointer to the head
 * @line_number: Line number in a file
 *
 * Return: No return
 */

void opcode_rotr(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;
	int i = 0;

	current = malloc(sizeof(stack_t));
	if (current == NULL)
		exit(EXIT_FAILURE);
	original = *h;
	while (original->next != NULL)
		original = original->next;
	opcode_pop(&current, line_number);
	while (original != NULL)
	{
		opcode_print(&current, line_number);
		plain.e = original->n;
		printf("Rotr: %d, Plain.e: %d\n", original->n, plain.e);
		opcode_push(&current, original->n);
		opcode_print(&current, original->n);
		original = original->prev;
	}
	*h = current;
	if (line_number)
		i++;
}
