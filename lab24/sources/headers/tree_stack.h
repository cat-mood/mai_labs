#pragma once

#include <stdlib.h>
#include "tree.h"

typedef struct {
    tree* buf;
    int size;
    int cap;
} tree_stack;

tree_stack ts_init();
void ts_destroy(tree_stack* s);
bool ts_is_empty(tree_stack* s);
bool ts_push(tree_stack* s, tree t);
tree ts_pop(tree_stack* s);
