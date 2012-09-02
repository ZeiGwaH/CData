#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>

typedef struct Queue Queue;
typedef struct Item Item;

/* Create a queue object */
Queue* queue_new(void);

/* Test wether queue is empty */
int queue_empty(Queue* p_queue);

/* Get the queue size */
size_t queue_size(Queue* p_queue);

/* Get the first item added */
void* queue_front(Queue* p_queue);

/* Add an item to the queue */
void queue_push(Queue* p_queue, void* data);

/* Remove the first item added */
void queue_pop(Queue* p_queue);

/* Destroy a queue object */
void queue_delete(Queue* p_queue);

#endif
