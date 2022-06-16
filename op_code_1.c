#include "monty.h"

/**
 * opcode_push - A function that adds a new node at the end
 * of a linked list
 * @head: Pointer to the pointer to the head of the linked list
 * @n: Line number in a file
 * Return: No return
 */

void opcode_push(stack_t **head, unsigned int n)
{
	stack_t *current, *past;
		
	if (n)
	{
		n = n + 1;
		n = n - 1;
	}
	past = malloc(sizeof(stack_t));
	if (past != NULL)
	{

		past->n = plain.e;
		past->next = NULL;
	
		if (*head == NULL)
		{
			past->prev = NULL;
			*head = past;
		}
		else
		{
			current = *head;
			while (current->next != NULL)
				current = current->next;
			current->next = past;
			past->prev = current;
		}
	}
	else
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
}



/**
 * print_dlistint - A function that prints all the elements in a linked list
 * @h: Pointer to the head of the linked list
 * @line: Line number in a file
 * Return: No return
 */

void opcode_print(stack_t **h, unsigned int line)
{
	stack_t *current;
	int w = 0, p = 0;
	
	if (*h != NULL) 
	{
		current = *h;
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
	}
	if (line)
		p++;
}

/**
 * opcode_pint - Function that prints the value at the top stack
 * @h: pointer to the pointer to the head
 * @line_number: Line_number of the file
 * Return: No return
 */
void opcode_pint(stack_t **h, unsigned int line_number)
{
	stack_t *current;

	if(*h == NULL)
	{
		printf("L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	
	current = *h;
	while(current->next != NULL)
		current = current->next;
	printf("%d\n", current->n);
}

/**
 * opcode_pop - A function that removes the top element in a stack
 * @h: Pointer to the pointer to the head
 * @line_number: Line number in a file
 *
 * Return: No return
 */
void opcode_pop(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;

	if (*h == NULL)
	{
		printf("L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current = *h;
		while (current->next != NULL)
		{
			original = current;
			current = current->next;
		}
		if (current->prev == NULL)
		{
			free(current);
			*h = NULL;
		}
		else
		{
			original->next = NULL;
			free(current);
		}
	}
}
