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
 * split_line - Function to split
 * the inputed commands into arguments
 * @line: Inputed argument
 * Return: Return the argumented inputs
 */
int string_tokenizer(char* str, char **tokens, char *delimiter)
{
	int tokens_count = 0;
	char* token = strtok(str, delimiter);
	while (token != NULL){
		(tokens[tokens_count]) = token;
		tokens_count++;
		token = strtok(NULL, delimiter);
	}
	tokens[tokens_count++] = NULL;
	return tokens_count;
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

