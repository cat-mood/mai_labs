#pragma once
#include <stdbool.h>

typedef struct {
    double * buf;
    int head;
    int size;
    int cap;
} dbl_vec;

dbl_vec init();
void destroy(dbl_vec *v);
bool push_back(dbl_vec *v, double val);
bool push_front(dbl_vec *v, double val);
double pop_back(dbl_vec *v);
double pop_front(dbl_vec *v);
bool is_empty(dbl_vec *v);
int get_size(dbl_vec *v);
bool set_size(dbl_vec *v, int new_size);
double get_el(dbl_vec *v, int idx);
void set_el(dbl_vec *v, int idx, double val);
