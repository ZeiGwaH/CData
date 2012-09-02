#include <stdlib.h>
#include "stack.h"

struct Item
{
    Item* p_next;
    void* data;
};

struct Stack
{
    Item* p_top;
    size_t size;
};

Stack*
stack_new(void)
{
    Stack* p_stack = malloc(sizeof(Stack));
    if(p_stack == NULL)
        return NULL;

    p_stack -> p_top = NULL;
    p_stack -> size = 0;

    return p_stack;
}

void*
stack_top(Stack* p_stack)
{
    return p_stack -> p_top -> data;
}

void
stack_push(Stack* p_stack, void* data)
{
    Item* p_item = malloc(sizeof(Item));
    if(p_item == NULL)
        exit(EXIT_FAILURE);

    if(stack_empty(p_stack))
        p_item -> p_next = NULL;
    else
        p_item -> p_next = p_stack -> p_top;

    p_item -> data = data;
    p_stack -> p_top = p_item;
    p_stack -> size ++;
}

void
stack_pop(Stack* p_stack)
{
    Item* p_item = p_stack -> p_top;
    p_stack -> p_top = p_item -> p_next;
    p_stack -> size --;
    free(p_item);
}

int
stack_empty(Stack* p_stack)
{
    return p_stack -> size ? 0 : 1;
}

size_t
stack_size(Stack* p_stack)
{
    return p_stack -> size;
}

void
stack_delete(Stack* p_stack)
{
    while(!stack_empty(p_stack))
        stack_pop(p_stack);
    free(p_stack);
}
