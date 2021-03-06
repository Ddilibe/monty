#include "monty.h"
#include <stdio.h>

/**
 * _strcpy - copies the string pointed to by src
 * including the treminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination
 * @src: source
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}


/**
 * string_tokenizer - Function to split
 * the inputed commands into arguments
 * @str: string to divide
 * @tokens: pointer at which strings should be stored
 * @delimiter: delimiters to be used
 * Return: Return the argumented inputs
 */
int string_tokenizer(char *str, char **tokens, char *delimiter)
{
	int tokens_count = 0;
	char *token = strtok(str, delimiter);

	while (token != NULL)
	{
		(tokens[tokens_count]) = token;
		tokens_count++;
		token = strtok(NULL, delimiter);
	}
	tokens[tokens_count++] = NULL;
	return (tokens_count);
}



/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}


/**
 * count_stack - Function for counting the stack
 * @h: pointer to the pointer to the head
 *
 * Return: the numer of elements in s stack
 */
int count_stack(stack_t **h)
{
	int i = 0;
	stack_t *current;

	current = *h;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

/**
 * comment - Function to determin argumented line
 * @c: Pointer to a string
 *
 * Return: 1 if true another if false
 */
int comment(char *c)
{
	int i, o;

	i = strlen(c);
	for (o = 0; o < i; o++)
	{
		if (c[o] == '#')
		{
			return (1);
		}
	}
	return (0);
}
