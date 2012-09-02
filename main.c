#include <stdio.h>
#include <stdlib.h>

#include "inc/list.h"

void 
display(void* data)
{
    printf("%d < ", (int) data);
}

int
main(void)
{
    List* p_list = list_new();
    if(p_list == NULL)
        exit(EXIT_FAILURE);

    list_cons_back(p_list, (void*) 1);
    list_cons_back(p_list, (void*) 2);
    list_cons_front(p_list, (void*) 0);

    list_print(p_list, display);

    list_delete(p_list);
    return EXIT_SUCCESS;
}
