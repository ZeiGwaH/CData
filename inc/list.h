#ifndef LIST_H_
#define LIST_H_

#include <stddef.h>

typedef struct Item Item;
typedef struct List List;

/* Create a list object */
List* list_new(void);

/* Add item at the top of the list */
void list_cons_front(List* p_list, void* data);

/* Add item at the end of the list */
void list_cons_back(List* p_list, void* data);

/* Remove the first item added */
void list_pop_front(List* p_list);

/* Remove the last item added */
void list_pop_back(List* p_list);

/* Get the list size */
size_t list_size(List* p_list);

/* Test wether list is empty */
int list_empty(List* p_list);

/* Print a list */
void list_print(List* p_list, void (*p_callback)(void*));

/* Remove all items in the list */
void list_clear(List* p_list);

/* Destroy a list object */
void list_delete(List* p_list);

#endif
