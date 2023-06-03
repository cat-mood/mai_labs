#include "headers/iterator.h"
#include <stdio.h>

iter iter_begin(list* l) {
    iter i;
    i.lst = l;
    i.prev = NULL;
    return i;
}

iter iter_end(list* l) {
    iter it;
    it.lst = l;
    it.prev = l->first;
    for (int i = 0; i < l->size - 1; i++) {
        it.prev = it.prev->next;
    }
    return it;
}

bool iter_eq(iter it1, iter it2) {
    if (it1.prev == NULL) {
        if (it2.prev == NULL) {
            return true;
        }
        return false;
    }
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

void add_el(iter* it, uint el) {
    node* elem = malloc(sizeof(node));
    elem->val = el;
    if (it->prev == NULL) {   // when add in the begin
        elem->next = it->lst->first;
        it->lst->first = elem;
        if (it->lst->last == NULL) {  // when the list has no elements
            it->lst->last = elem;
            elem->next = elem;
        }
    } else if(it->prev->next == NULL) {  // when add in the end
        elem->next = it->lst->first;
        it->lst->last = elem;
        it->prev->next = elem;
    } else {
        elem->next = it->prev->next;
        it->prev->next = elem;
    }
    it->prev = elem;
    it->lst->size++;
}

void delete_el(iter* it) {
    node* elem;
    if (it->prev == NULL) {   // when delete in the begin
        elem = it->lst->first;
        it->lst->first = it->lst->first->next;
        if (it->lst->first == elem) {   // when the list has only one element
            it->lst->first = NULL;
        }
        if (it->lst->first == NULL) {     // when the list has no elements
            it->lst->last = NULL;
        }
    } else if (it->prev->next->next == NULL) {    // when delete in the end
        elem = it->prev->next;
        it->prev->next = it->lst->first;
        it->lst->last = it->prev;
    } else {
        elem = it->prev->next;
        it->prev->next = it->prev->next->next;
    }
    free(elem);
}

void print_list(list* l) {
    iter it = iter_begin(l);
    while (!iter_eq(it, iter_end(l))) {
        printf("%d ", iter_get_val(&it));
        iter_inc(&it);
    }
    printf("\n");
}
