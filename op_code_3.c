#include "monty.h"

void opcode_div(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;
	int w;
	
	w = count_stack(h);
	if (w > 2)
	{
		current = *h;
		
		while(current->next != NULL)
		{
			original = current;
			current = current->next;
		}
		if (current->n == 0)
		{
			printf("L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		original->n = original->n/current->n;
		original->next = NULL;
		free(current);
	}
	else
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

void opcode_mul(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;
	int w;
	
	w = count_stack(h);
	if (w > 2)
	{
		current = *h;
		
		while(current->next != NULL)
		{
			original = current;
			current = current->next;
		}
		original->n = original->n * current->n;
		original->next = NULL;
		free(current);
	}
	else
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

void opcode_mod(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original;
	int w;
	
	w = count_stack(h);
	if (w > 2)
	{
		current = *h;
		
		while(current->next != NULL)
		{
			original = current;
			current = current->next;
		}
		if (current->n == 0)
		{
			printf("L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		original->n = original->n % current->n;
		original->next = NULL;
		free(current);
	}
	else
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}


void opcode_rotl(stack_t **h, unsigned int line_number)
{
	stack_t *current, *original, *past;
	int i = 0;
	
	current = *h;
	past = *h;
	
	while (current->next != NULL)
	{
		original = current;
		current = current->next;
	}
	
	original->next = NULL;
	current->prev = NULL;
	past->prev = current;
	current->next = past;
	*h = current;

	if (line_number)
		i++;
}
