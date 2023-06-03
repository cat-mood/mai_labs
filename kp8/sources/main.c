#include "headers/list.h"
#include "headers/iterator.h"
#include <stdio.h>

int main() {
    list l = new_list();
    int n;
    printf("Enter number of elements in the list:\n");
    scanf("%d", &n);
    printf("Fill the list:\n");
    uint el;
    iter it = iter_begin(&l);
    for (int i = 0; i < n; i++) {
        scanf("%u", &el);
        add_el(&it, el);
        iter_inc(&it);
    }
    printf("List:\n");
    print_list(&l);

    return 0;
}
