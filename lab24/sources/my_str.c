#include <headers/my_str.h>

my_str init() {
    my_str s;
    s.buf = malloc(sizeof(char) * MIN_CAP_STR);
    s.cap = MIN_CAP_STR;
    s.size = 0;
    return s;
}

static void increase_buf(my_str* s) {
    if (s->cap < s->size * 2) {
        s->buf = realloc(s->buf, sizeof(char) * s->cap * 2);
    }
}

void add_char(my_str* s, char val) {
    increase_buf(s);
    s->buf[s->size] = val;
    s->size++;
}

void destroy_str(my_str* s) {
    free(s->buf);
}