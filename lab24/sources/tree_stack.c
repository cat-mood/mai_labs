#include "headers/tree_stack.h"
#define MIN_CAP 20

tree_stack ts_init() {
    tree_stack s;
    s.cap = MIN_CAP;
    s.buf = malloc(sizeof(tree) * s.cap);
    s.size = 0;
    return s;
}

void ts_destroy(tree_stack* s) {
    s->size = 0;
    free(s->buf);
}

bool ts_is_empty(tree_stack* s) {
    return s->size == 0;
}

static bool increase_buf(tree_stack* s) {
    if (s->cap >= s->size * 2) {
        return true;
    }
    int new_cap = s->cap * 2;
    if (new_cap < MIN_CAP) {
        new_cap = MIN_CAP;
    }
    tree_stack* tmp = realloc(s, sizeof(tree) * new_cap);
    if (tmp == NULL) {
        return false;
    }
    s->buf = tmp;
    s->cap = new_cap;
    return true;
}

static bool decrease_buf(tree_stack* s) {
    if (s->size >= s->cap / 4) {
        return true;
    }
    int new_cap = s->cap / 2;
    if (new_cap < MIN_CAP) {
        new_cap = MIN_CAP;
    }
    tree_stack* tmp = realloc(s, sizeof(tree) * new_cap);
    if (tmp == NULL) {
        return false;
    }
    s->buf = tmp;
    s->cap = new_cap;
    return true;
}

bool ts_push(tree_stack* s, tree t) {
    if (!increase_buf(s)) {
        return false;
    }
    s->buf[s->size] = t;
    s->size++;
}

tree ts_pop(tree_stack* s) {
    tree t = s->buf[s->size - 1];
    s->size--;
    decrease_buf(s);
    return t;
}
