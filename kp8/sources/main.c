#include "headers/list.h"
#include "headers/iterator.h"
#include <stdio.h>

// delete elements in range from start to end (start <= n < end)
void delete_in_range(list* l, uint start, uint end) {
    iter it = iter_begin(l);
    bool is_first_deleted = false;
    do {
        if (!is_list_empty(l) && start <= iter_get_val(&it) && iter_get_val(&it) < end) {
            delete_el(&it);
            if (iter_eq(it, iter_begin(l))) {
                is_first_deleted = true;
            }
        } else {
            iter_inc(&it);
            is_first_deleted = false;
        }
    } while (!iter_eq(it, iter_begin(l)) || is_first_deleted);
}

void add_menu(list* l) {
    iter it = iter_begin(l);
    printf("Enter idx of element: ");
    int idx;
    scanf("%d", &idx);
    if ((l->size == 0 && idx != 0) || (l->size != 0 && (idx > l->size - 1 || idx < 0))) {
        printf("Wrong idx!\n");
        return;
    }
    printf("Enter number: ");
    uint el;
    scanf("%u", &el);
    for (int i = 0; i < idx; i++) {
        iter_inc(&it);
    }
    add_el(&it, el);
}

void delete_menu(list* l) {
    iter it = iter_begin(l);
    printf("Enter idx of element: ");
    int idx;
    scanf("%d", &idx);
    if (idx > l->size - 1 || idx < 0) {
        printf("Wrong idx!\n");
        return;
    }
    for (int i = 0; i < idx; i++) {
        iter_inc(&it);
    }
    delete_el(&it);
}

void delete_in_range_menu(list* l) {
    printf("Enter range [a; b):\n");
    uint left;
    scanf("%u", &left);
    uint right;
    scanf("%u", &right);
    delete_in_range(l, left, right);
}

void menu(list* l) {
    int c;
    do {
        printf("Options: \n");
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Delete in range\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("\nChoose option: ");
        c = getchar();
        if (c == '1') {
            add_menu(l);
        } else if (c == '2') {
            delete_menu(l);
        } else if (c == '3') {
            delete_in_range_menu(l);
        } else if (c == '4') {
            print_list(l);
        }  else if (c == '5' || c == EOF) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Wrong option!\n");
        }
        while (c != '\n') {
            c = getchar();
        }
    } while (c != '5');
}

int main() {
    list l = new_list();
    menu(&l);
    destroy_list(&l);

    return 0;
}
