#include"list.h"
#include<stdio.h>

Node_t* createNode(uint32_t val)
{
    Node_t* node = (Node_t*) malloc(sizeof(Node_t));
    node->value=val;
    node->next=NULL;

    return node;
}

void dropNode(Node_t* node) {
    free(node);
    //node = NULL;
}


void show(const List_t* const list)
{
    Node_t* current_node = list->head;
    while (current_node)
    {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }

    printf("\n");
}

void destroyList(List_t* list)
{
    Node_t* to_drop = NULL;
    while(list->head)
    {   
        to_drop = list->head;
        list->head = list->head->next;
        dropNode(to_drop);
    }
}

////////////////////// Operators ///////////////////////

// GET ################################################

Node_t* getNode(List_t* list, uint32_t pos)
{
    Node_t* current_node = NULL;
    uint32_t index       = 0;

    if (pos < list->size) {
        current_node = list->head;
        while (++index <= pos) current_node = current_node->next;
    }
    return current_node;
}

uint32_t at(List_t* list, uint32_t pos)
{
    return getNode(list, pos)->value;
}

// ADD ################################################

void addFirst(List_t* list, uint32_t val)
{
    Node_t* node = createNode(val);

    //     null 
    //      ^
    //     head
    if (!list->head){
        list->head = node;
    }
    else {
        //     node1 -> ... -> nodeN -> null
        //       ^
        //     head
        node->next = list->head;
        list->head = node;
    }
    ++list->size;
}

void addLast(List_t* list, uint32_t val)
{
    Node_t* node = createNode(val);
    //     null 
    //      ^
    //     head
    if (!list->head){
        list->head = node;
    }
    else {
        //     node1 -> ... -> nodeN -> null
        //                       ^
        //                     head
        //Node_t* current_node = list->head;
        //while (current_node->next){
        //    current_node = current_node->next;
        //}
        //current_node->next = node;
        Node_t* last_node = getNode(list, list->size-1);
        last_node->next   = node;
    }
    ++list->size;
}

void add(List_t* list, uint32_t val, uint32_t pos)
{
    if      (pos == 0) addFirst(list, val);
    else if (pos < list->size)
    {
        // Add pos 2:
        //     node1 -> node2 -> node3 -> node4 -> null
        //       ^                 ^
        //     head               here!
        //
        //     node1 -> node2 ->  new_nodeX  -> node3 -> node4 -> null
        //       ^
        //     head
        //
        Node_t* node          = createNode(val);
        Node_t* previous_node = getNode(list, pos-1); 
        node->next = previous_node->next;
        previous_node->next = node;
        ++list->size;
    }
}

// DROP ################################################

void dropFirst(List_t* list)
{
    // 
    //     node1 -> node2 -> node3 -> node4 -> null
    //        ^
    //      head
    //
    // 
    //     node1 ->  node -> node -> node -> null
    //       ^        ^
    //     DROP!     head
    //
    if (list->head){
        Node_t* to_drop = list->head;
        list->head      = list->head->next;
        dropNode(to_drop);
        --list->size;
    }
}

void dropLast(List_t* list)
{
    if (!list->head) return;
    if (!list->head->next) { 
        dropNode(list->head);
        list->head = NULL;
    }
    else {
        // 
        //     node1 -> node2 -> node3 -> node4 -> null
        //       ^                          ^        
        //      head                      DROP!
        //
        //     node1 -> node2 -> node3 -> null
        //       ^
        //      head
        //
        Node_t* penultimate_node = getNode(list, list->size-2);
        dropNode(penultimate_node->next);
        penultimate_node->next = NULL;
    }
    --list->size;
}

void drop(List_t* list, uint32_t pos)
{
    if      (pos == 0) dropFirst(list);
    else if (pos < list->size){
        // Drop pos 2
        //     node1 -> node2 -> node3 -> node4 -> null
        //       ^                 ^        
        //      head              DROP!
        //
        //     node1 -> node2 -> node4 -> null
        //       ^       
        //      heads
        //
        Node_t* previous_node = getNode(list, pos-1);
        Node_t* to_drop       = previous_node->next;
        previous_node->next   = previous_node->next->next;
        dropNode(to_drop);
        --list->size;
    }
}

