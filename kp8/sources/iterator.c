#include "headers/iterator.h"

iter iter_begin(list* l) {
    iter i;
    i.lst = l;
    i.prev = NULL;
    return i;
}

iter iter_end(list* l) {
    iter i;
    i.lst = l;
    i.prev = l->last;
    return i;
}

bool iter_eq(iter it1, iter it2) {
    return it1.prev->next == it2.prev->next;
}

void iter_inc(iter* it) {
    if (it->prev == NULL) {
        it->prev = it->lst->first;
    } else {
        it->prev = it->prev->next;
    }
}

uint iter_get_val(iter* it) {
    if (it->prev == NULL) {
        return it->lst->first->val;
    }
    return it->prev->next->val;
}
