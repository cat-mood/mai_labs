#include "headers/int_vec.h"
#include "headers/tree.h"
#include <stdio.h>
#include <ctype.h>

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int check_priority(char op) {
    if (op == '^') {
        return 3;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '(') {
        return 0;
    }
}

int_vec postfix() {
    char c;
    int_vec opstack = init();
    int_vec list = init();
    do {
        c = getchar();
        if (c == '(') {
            push_back(&opstack, c);
        } else if (c == ')') {
            char buf = pop_back(&opstack);
            while (buf != '(') {
                push_back(&list, ' ');
                push_back(&list, buf);
                buf = pop_back(&opstack);
            }
        } else if (is_op(c)) {
            push_back(&list, ' ');
            if (is_empty(&opstack)) {
                push_back(&opstack, c);
            } else if (c == '^'){
                push_back(&opstack, c);
            } else {
                char buf = pop_back(&opstack);
                while (check_priority(c) <= check_priority(buf) && !is_empty(&opstack)) {
                    push_back(&list, buf);
                    push_back(&list, ' ');
                    buf = pop_back(&opstack);
                }
                if (check_priority(c) <= check_priority(buf)) {
                    push_back(&list, buf);
                    push_back(&list, ' ');
                    printf("DEBUG: %c\n", buf);
                } else {
                    push_back(&opstack, buf);
                }
                push_back(&opstack, c);
            }
        } else if (isalpha(c) || isdigit(c)) {
            push_back(&list, c);
        } else if (c == '\n') {
            break;
        } else if (c == ' ') {
            continue;
        }
    } while (c != '\n');
    while (!is_empty(&opstack)) {
        push_back(&list, ' ');
        push_back(&list, pop_back(&opstack));
    }
    destroy(&opstack);
    return list;
}

void print_vec(int_vec* v) {
    for (int i = 0; i < get_size(v); i++) {
        putchar(get_el(v, i));
    }
    putchar('\n');
}

tree postfix_to_tree(int_vec* post) {
    if (is_empty(post)) {
        return empty_tree();
    }
    int root = pop_back(post);
    tree right = postfix_to_tree(post);
    tree left = postfix_to_tree(post);
    return build_tree(root, left, right);
}

int main() {
    int_vec post = postfix();
    print_vec(&post);
    tree expr = postfix_to_tree(&post);
    print_tree(expr);
    destroy(&post);
    return 0;
}