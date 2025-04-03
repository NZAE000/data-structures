#ifndef __NODE__H
#define __NODE__H
#include<stdint.h>
#include<stdlib.h>

typedef struct node {
    uint32_t    value;
    struct node* next;
} Node_t;

#endif