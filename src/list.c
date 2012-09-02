#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Item
{
    void* data;
    Item* p_next;
};

struct List
{
    Item* p_head;
    Item* p_tail;
    size_t size;
};

List*
list_new(void)
{
    List* p_list = malloc(sizeof(List));
    if(p_list == NULL)
        return NULL;

    p_list -> p_head = NULL;
    p_list -> p_tail = NULL;
    p_list -> size = 0;

    return p_list;
}

void
list_cons_front(List* p_list, void* data)
{
    Item* p_item = malloc(sizeof(Item));
    if(p_item == NULL)
        exit(EXIT_FAILURE);

    p_item -> data = data;
    p_item -> p_next = p_list -> p_head;

    p_list -> p_head = p_item;
    if(list_empty(p_list))
        p_list -> p_tail = p_item;
    p_list -> size++;
}

void
list_cons_back(List* p_list, void* data)
{
    Item* p_item = malloc(sizeof(Item));
    if(p_item == NULL)
        exit(EXIT_FAILURE);

    p_item -> data = data;
    p_item -> p_next = NULL;

    if(list_empty(p_list))
    {
        p_list -> p_tail = p_item;
        p_list -> p_head = p_item;
    }
    else
    {
        p_list -> p_tail -> p_next = p_item;
        p_list -> p_tail = p_item;
    }

    p_list -> size++;
}

void
list_pop_front(List* p_list)
{
    if(list_empty(p_list))
        return;
    else if(list_size(p_list) == 1)
    {
        free(p_list -> p_head);
        p_list -> p_head = NULL;
        p_list -> p_tail = NULL;
        p_list -> size--;
        return;
    }

    Item* p_item = p_list -> p_head;
    p_list -> p_head = p_item -> p_next;
    p_list -> size--;
    free(p_item);
}

void
list_pop_back(List* p_list)
{
    if(list_empty(p_list))
        return;
    else if(p_list -> size == 1)
    {
        free(p_list -> p_head);
        p_list -> p_head = NULL;
        p_list -> p_tail = NULL;
        p_list -> size--;
        return;
    }

    int i;
    Item* p_item = p_list -> p_head;
    for(i = 1; i < p_list -> size - 1; i++)
        p_item = p_item -> p_next;

    p_list -> p_tail = p_item;
    p_list -> size--;
    free(p_item -> p_next);
    p_item -> p_next = NULL;
}

size_t
list_size(List* p_list)
{
    if(p_list == NULL) return 0;
    return p_list -> size;
}

int
list_empty(List* p_list)
{
    if(p_list == NULL) return 1;
    return p_list -> size ? 0 : 1;
}

void
list_print(List* p_list, void (*p_callback)(void*))
{
    Item* p_item = p_list-> p_head;
    while(p_item != NULL)
    {
        (*p_callback)(p_item -> data);
        p_item = p_item -> p_next;
    }
    printf("NULL\n");
}

void
list_clear(List* p_list)
{
    while(!list_empty(p_list))
        list_pop_front(p_list);
}

void
list_delete(List* p_list)
{
    list_clear(p_list);
    free(p_list);
}
