#include "headers/tree_stack.h"
#include <stdlib.h>

void ts_init(tree_stack *s){
    s->first = NULL;
}

bool ts_is_empty(tree_stack *s){
    if (s->first == NULL){
        return true;
    }
    return false;
}

void ts_push(tree_stack *s, tree val){
    ts_node *new_node = malloc(sizeof(tree));
    new_node->val = val;
    new_node->next = s->first;
    s->first = new_node;
}

tree ts_pop(tree_stack *s){
    ts_node *old = s->first;
    s->first = old->next;
    tree v = old->val;
    free(old);
    return v;
}

void ts_destroy(tree_stack *s){
    ts_node *cur = s->first;
    while (cur != NULL){
        ts_node *next = cur->next;
        free(cur);
        cur = next;
    }
    s->first = NULL;
}
