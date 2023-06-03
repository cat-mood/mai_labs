#pragma once
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
typedef unsigned int uint;

struct node {
    uint val;
    node* next;
};

typedef struct {
    int size;
    node* first;
    node* last;
} list;

list new_list();
void destroy_list(list* l);
