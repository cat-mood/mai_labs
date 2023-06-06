#pragma once
#include <stdbool.h>
#include "expression.h"

typedef struct {
    token * buf;
    int head;
    int size;
    int cap;
} token_vec;

token_vec tkn_init();
void tkn_destroy(token_vec *v);
bool tkn_push_back(token_vec *v, token val);
bool tkn_push_front(token_vec *v, token val);
token tkn_pop_back(token_vec *v);
token tkn_pop_front(token_vec *v);
bool tkn_is_empty(token_vec *v);
int tkn_get_size(token_vec *v);
bool tkn_set_size(token_vec *v, int new_size);
token tkn_get_el(token_vec *v, int idx);
void tkn_set_el(token_vec *v, int idx, token val);
