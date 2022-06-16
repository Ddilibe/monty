#ifndef _MONTY_H_
#define _MAIN_H_

#define MAX_LENGTH 80

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* 
 * The prototypes for monty
 */
int file_extension(char *s);
int string_tokenizer(char* str, char **tokens, char *delimiter);
FILE *open_file(char *file);
void close_file(FILE *file);
void print_out(FILE *file);
char *get_array(char *po, char **sopp);
void opcode_push(stack_t **head, unsigned int n);
void opcode_print(stack_t **h, unsigned int line);
void command(stack_t **head, char *line);
int _atoi(char *s);


#endif