#include "monty.h"

/**
 * opcode_push - A function that adds a new node at the end
 * of a linked list
 * @head: Pointer to the pointer to the head of the linked list
 * @n: Value to be inputed into the linked list
 * Return: Address if succeed NULL if fail
 */

void opcode_push(stack_t **head, unsigned int n)
{
	stack_t *current, *past;

	past = malloc(sizeof(stack_t));
	if (past != NULL)
	{

		past->n = n;
		past->next = NULL;
	
		if (*head == NULL)
		{
			past->prev = NULL;
			*head = past;
			printf("Created a new node\n");
		}
		else
		{
			current = *head;
			while (current->next != NULL)
				current = current->next;
			current->next = past;
			past->prev = current;
			printf("Updated the stack\n");
		}
	}
}



/**
 * print_dlistint - A function that prints all the elements in a linked list
 * @h: Pointer to the head of the linked list
 * Return: Number of nodes in the linked list
 */

void opcode_print(stack_t **h, unsigned int line)
{
	stack_t *current;
	int w = 0;
	
	printf("About to assign h to current\n");
	current = *h;
	printf("Assigned h to current\n");
	while (current->next != NULL)
	{	
		current = current->next;
		w++;
	}
	while(current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
	line++;	
}

