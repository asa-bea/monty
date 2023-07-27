#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>



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

/**
 * struct bus_s - hold variables
 * desc - Maintain variables meant for utilization across various functions
 * within the project, including those necessitating memory allocation and
 * & freeing
 * @file: Connects to the stream from file
 * @comment: A string rep'ing the line of text that will be read from the stream
 * @line_number: to track the current line number
 * @tokens: used to store tokens from line
 * @instruction: an instruction from a line
 * @n_tokens; number of tokens created from a line
 * @head: head/top of the stack (doubly linked lists of struct stack_s)
 * @stack_len: tracks the number of nodes in the stack
 * @stack: used to determine whether to use stack/queue data structure
 *
 */
typedef struct bus_s
{
        FILE *file;
        char *comment;
	unsigned int line_number;
	char **tokens;
	int n_tokens;
	instruction_t *instruction;
	stack_t *head;
	int stack_len;
	int stack;
} bus_t;

extern bus_t *arguments;

int dprintf(int fd, const char *format, ...);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
FILE *fdopen(int fd, const char *mode);

void arguments_validation(int argc);
void arguments_init();
void get_file(char *fileName);
void close_file(void);
void to_tokenize_comment(void);
void to_free_tokens(void);
void to_run_instruction(void);
void to_get_instruction(void);
void free_arguments();
void get_file_failed(char *filename)








#endif /*MONTY_H*/
