#pragma once
#include "list.h"

typedef struct{
    list* lst;
    node* prev;
} iter;

iter iter_begin(list* l);
bool iter_eq(iter it1, iter it2);
void iter_inc(iter* it);
uint iter_get_val(iter* it);
void add_el(iter* it, uint el);
void delete_el(iter* it);
void print_list(list* l);
