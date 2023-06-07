#pragma once
#include <stdbool.h>
#include "tree.h"

typedef struct ts_node ts_node;

struct ts_node{
    tree val;
    ts_node *next;
};

typedef struct{
    ts_node *first;
} tree_stack;

void ts_init(tree_stack *s);
void ts_destroy(tree_stack *s);
tree ts_pop(tree_stack *s);
void ts_push(tree_stack *s, tree val);
bool ts_is_empty(tree_stack *s);
