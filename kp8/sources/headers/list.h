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
bool add_el(iter* it, uint el);
void delete_el(iter it);
void print_list(list* l);
