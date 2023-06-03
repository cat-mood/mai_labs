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
        next = cur->next;
        free(cur);
    }
}

bool add_el(iter* it, uint el) {
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
