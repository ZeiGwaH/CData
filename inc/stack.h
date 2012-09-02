#ifndef STACK_H_
#define STACK_H_

#include <stddef.h>

typedef struct Stack Stack;
typedef struct Item Item;

/* Create a stack object */
Stack* stack_new(void);

/* Get the last item added */
void* stack_top(Stack* p_stack);

/* Add an item to the stack */
void stack_push(Stack* p_stack, void* data);

/* Remove the last item added */
void stack_pop(Stack* p_stack);

/* Test wether stack is empty */
int stack_empty(Stack* p_stack);

/* Get the stack size */
size_t stack_size(Stack* p_stack);

/* Destroy a stack object */
void stack_delete(Stack* p_stack);

#endif
