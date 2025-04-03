#ifndef __LIST__H
#define __LIST__H
#include "node.h"

typedef struct list {
    Node_t* head;
    uint32_t size;
    
} List_t;

Node_t* createNode(uint32_t val);
void dropNode(Node_t*);
void show(const List_t* const);
void destroyList(List_t*);

// Operators ///////////////////////

// GET
Node_t* getNode(List_t*, uint32_t pos);
uint32_t at(List_t*, uint32_t pos);

// ADD
void addFirst(List_t*, uint32_t val);
void addLast(List_t*, uint32_t val);
void add(List_t*, uint32_t val, uint32_t pos);

// DROP
void dropFirst(List_t*);
void dropLast(List_t*);
void drop(List_t*, uint32_t pos);


#endif