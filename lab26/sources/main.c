#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include "headers/int_vec.h"

int delete_max(int_vec* deq) {
    int el, max = INT_MIN;
    int_vec buf = init();
    bool is_deleted = false;
    while (!is_empty(deq)) {
        el = pop_back(deq);
        if (el > max) {
            max = el;
        }
        push_front(&buf, el);
    }
    while (!is_empty(&buf)) {
        el = pop_back(&buf);
        if (el == max && !is_deleted) {
            is_deleted = true;
            continue;
        }
        push_back(deq, el);
    }
    destroy(&buf);
    return max;
}

void selection_sort(int_vec* deq) {
    int_vec buf = init();
    int val;
    while (!is_empty(deq)) {
        val = delete_max(deq);
        push_back(&buf, val);
    }
    while (!is_empty(&buf)) {
        push_front(deq, pop_back(&buf));
    }
    destroy(&buf);
}

bool input_deq(int_vec* deq) {
    int n = 0, c = getchar();
    bool is_negative = false;
    while (c != '\n') {
        if (c == ' ') {
            if (is_negative) {
                n *= -1;
            }
            push_back(deq, n);
            n = 0;
            is_negative = false;
        } else if (c == '-') {
            is_negative = true;
        } else if (!isdigit(c)) {
            fprintf(stderr, "Not number was inputed!\n");
            return false;
        } else {
            n *= 10;
            n += c - '0';
        }
        c = getchar();
    }
    if (is_negative) {
        n *= -1;
    }
    push_back(deq, n);
    return true;
}

void print_deq(int_vec* deq) {
    int_vec buf = init();
    int el;
    while (!is_empty(deq)) {
        el = pop_back(deq);
        printf("%d ", el);
        push_back(&buf, el);
    }
    while (!is_empty(&buf)) {
        el = pop_back(&buf);
        push_back(deq, el);
    }
    destroy(&buf);
    printf("\n");
}

int main() {
    int_vec deq = init();
    if (!input_deq(&deq)) {
        return 1;
    }
    // delete_max(&deq);
    // printf("Deleted max:\n");
    // print_deq(&deq);
    selection_sort(&deq);
    printf("Sorted:\n");
    print_deq(&deq);
    
    destroy(&deq);    

    return 0;
}
