#include <stdlib.h>
#include "queue.h"

struct Item
{
    Item* p_next;
    void* data;
};

struct Queue
{
    Item* p_head;
    Item* p_tail;
    size_t size;
};

Queue*
queue_new(void)
{
    Queue* p_queue = malloc(sizeof(Queue));
    if(p_queue == NULL)
        return NULL;

    p_queue -> p_head = NULL;
    p_queue -> p_tail = NULL;
    p_queue -> size = 0;

    return p_queue;
}

size_t
queue_size(Queue* p_queue)
{
    return p_queue -> size;
}

void*
queue_front(Queue* p_queue)
{
    return p_queue -> p_head -> data;
}


int
queue_empty(Queue* p_queue)
{
    return p_queue -> size ? 0 : 1;
}

void
queue_push(Queue* p_queue, void* data)
{
    Item* p_item = malloc(sizeof(Item));
    if(p_item == NULL || p_queue == NULL)
        exit(EXIT_FAILURE);

    p_item -> p_next = NULL;
    p_item -> data = data;

    if(queue_empty(p_queue))
    {
        p_queue -> p_head = p_item;
        p_queue -> p_tail = p_item;
    }
    else
    {
        p_queue -> p_tail -> p_next = p_item;
        p_queue -> p_tail = p_item;
    }

    p_queue -> size ++;
}

void
queue_pop(Queue* p_queue)
{
    Item* p_item = p_queue -> p_head;
    p_queue -> p_head = p_item -> p_next;
    p_queue -> size --;
    free(p_item);
}

void
queue_delete(Queue* p_queue)
{
    while(!queue_empty(p_queue))
        queue_pop(p_queue);
    free(p_queue);
}
