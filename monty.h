#ifndef MAIN_H
#define MAIN_H
/* Geting getline on GNU systems - ojo pestaña ceja */
#define _GNU_SOURCE

/* Libraries */
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
/* Macros */
#define _uu_  __attribute__((unused))
/* Shared variables */
extern bool band;
extern int number;
extern bool argInt;
extern bool mode;
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

void (*matcher(char *))(stack_t **, unsigned int);
/* Opcode_instructuions*/
void f_push(stack_t **, unsigned int);
void f_pop(stack_t **, unsigned int);
void f_pall(stack_t **, unsigned int);
void f_pint(stack_t **, unsigned int);
void f_swap(stack_t **, unsigned int);
void f_add(stack_t **, unsigned int);
void f_nop(stack_t **, unsigned int);
void f_sub(stack_t **, unsigned int);
void f_div(stack_t **, unsigned int);
void f_mul(stack_t **, unsigned int);
void f_mod(stack_t **, unsigned int);
void f_pchar(stack_t **, unsigned int);
void f_pstr(stack_t **, unsigned int);
void f_rotl(stack_t **, unsigned int);
void f_rotr(stack_t **, unsigned int);
void f_trash(stack_t **stack, _uu_ unsigned int line_number);
/* Main function */
char **parameter_to_str(char **);
void read_line(FILE *);
/* Functions help */
void dfree_list(stack_t *);
int validate_number(char *);
void _trim(char **str);

#endif /* MAIN_h */
