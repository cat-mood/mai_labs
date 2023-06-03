#include "headers/list.h"
#include "headers/iterator.h"

list new_list() {
    list l;
    l.size = 0;
    l.first = NULL;
    l.last = NULL;
    return l;
}

void destroy_list(list* l) {
    node* cur = l->first;
    node* next;
    for (int i = 0; i < l->size; i++) {
        cur = next;
        next = cur->next;
        free(cur);
    }
}

