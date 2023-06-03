#include "headers/iterator.h"
#include <stdio.h>

iter iter_begin(list* l) {
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
    return it->prev->next->val;
}

void add_el(iter* it, uint el) {
    node* elem = malloc(sizeof(node));
    elem->val = el;
    if (it->lst->size == 1) {
        it->lst->first->next = elem;
        elem->next = it->lst->first;
        it->lst->last = elem;
        it->prev = elem;
    } else if (it->prev == it->lst->last) {   // when add in the begin
        elem->next = it->lst->first;
        it->lst->first = elem;
        if (it->lst->last == NULL) {  // when the list has no elements
            it->lst->last = elem;
        }
        it->lst->last->next = elem;
    } else if (it->prev->next == it->lst->last) {  // when add in the end
        elem->next = it->lst->first;
        it->lst->last->next = elem;
        it->lst->last = elem;
    } else {   
        elem->next = it->prev->next;
        it->prev->next = elem;
    }
    it->lst->size++;
}

void delete_el(iter* it) {
    node* elem;
    elem = it->prev->next;
    if (it->prev->next == it->lst->first) {   // when delete in the begin
        it->lst->first = it->lst->first->next;
        if (it->lst->first == it->lst->last) {  // when the list has only one element
            it->lst->first = NULL;
        }
        if (it->lst->first == NULL) {     // when the list has no elements
            it->lst->last = NULL;
        }
        it->lst->last->next = it->lst->first;
    } else if (it->prev->next == it->lst->last) {    // when delete in the end
        it->prev->next = it->lst->first;
    } else {
        it->prev->next = it->prev->next->next;
    }
    free(elem);
}

void print_list(list* l) {
    iter it = iter_begin(l);
    do {
        printf("%d ", iter_get_val(&it));
        iter_inc(&it);
    } while (!iter_eq(it, iter_begin(l)));
    printf("\n");
}
