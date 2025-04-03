#include<stdio.h>
#include "list.h"

int main(void)
{   
    const uint32_t n_nodes = 10;
    List_t list = {.head=NULL, .size=0};

    for (uint32_t i=0; i<n_nodes; ++i){
        addFirst(&list, i+1);
        addLast(&list, i+1);
    }
    
    show(&list);
    add(&list, 3, 9);
    show(&list);

    dropFirst(&list);
    show(&list);

    dropLast(&list);
    show(&list);

    drop(&list, 4);
    show(&list);
    
    destroyList(&list);
    show(&list);

    return 0;
}