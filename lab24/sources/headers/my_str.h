#pragma once
#include <stdlib.h>
#define MIN_CAP_STR 20

typedef struct {
    char* buf;
    int cap;
    int size;
} my_str;

my_str init();
void add_char(my_str* s, char val);
void destroy_str(my_str* s);
