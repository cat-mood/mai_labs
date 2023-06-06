#include <stdlib.h>
#include "headers/token_vec.h"
#define MIN_CAP 32

static bool increase_buf(token_vec *v){
    if (v->size * 2 <= v->cap){
        return true;
    }
    int new_cap = 2 * v->cap;
    if (new_cap < MIN_CAP){
        new_cap = MIN_CAP;
    }
    token *tmp = realloc(v->buf, new_cap * sizeof(token));
    if (tmp == NULL){
        return false;
    }
    v->buf = tmp;
    v->cap = new_cap;
    return true;
}

static void decrease_buf(token_vec *v){
    if (v->size >= v->cap / 4){
        return;
    }
    int new_cap = v->cap / 2;
    if (new_cap < MIN_CAP){
        new_cap = MIN_CAP;
    }
    if (new_cap < v->cap){
        token* tmp = realloc(v->buf, new_cap * sizeof(token));
        if (tmp == NULL){
            return;
        }
        // обработка всех случаев располажения элементов в буфере
        if (v->head > new_cap - 1) {
            for (int i = v->head; i < v->cap; i++){
                v->buf[new_cap-(v->cap - i)] = v->buf[i];
            }
            v->head = v->cap - new_cap;
        } else if (v->head + v->size > new_cap - 1){
            for (int i = new_cap; i < v->head + v->size; i++){
                v->buf[i % new_cap] = v->buf[i];
            }
        }
        v->buf = tmp;
        v->cap = new_cap;
    }
}

bool tkn_set_size(token_vec *v, int new_size){
    if (new_size <= v->cap){
        v->size = new_size;
        decrease_buf(v);
        return true;
    }
    if (new_size == v->size + 1){
        if (!increase_buf(v)){
            return false;
        }
        v->size = new_size;
        return true;
    }
    // больше чем 1 элемент, increase не гарантирует, что всё влезет
    int new_cap = new_size;
    token *tmp = realloc(v->buf, new_cap * sizeof(token));
    if (tmp == NULL){
        return false;
    }
    v->buf = tmp;
    if (v->head + v->size > v->cap){
        int old_cap = v->cap;
        for (int i = old_cap; i >= v->head; i--){
            v->buf[i + new_cap - old_cap] = v->buf[i];
        }
        v->head += new_cap - old_cap;
    }
    v->size = new_size;
    v->cap = new_cap;
    return true;
}

token_vec tkn_init(){
    token_vec v;
    v.cap = MIN_CAP;
    v.head = 0;
    v.size = 0;
    v.buf = malloc(v.cap * sizeof(token));
    return v;
}

void tkn_destroy(token_vec* v){
    v->size = 0;
    v->head = -1;
    free(v->buf);
}

bool tkn_push_back(token_vec *v, token val){
    if (!increase_buf(v)){
        return false;
    }
    v->buf[(v->head + v->size) % v->cap] = val;
    v->size++;
    return true;
}

bool tkn_push_front(token_vec *v, token val){
    if (!increase_buf(v)){
        return false;
    }
    v->buf[(v->head - 1 + v->cap) % v->cap] = val;
    v->head = (v->head - 1 + v->cap) % v->cap;
    v->size++;
    return true;
}

token tkn_pop_back(token_vec *v){
    token res = v->buf[(v->head + v->size - 1) % v->cap];
    v->size--;
    decrease_buf(v);
    return res;
}

token tkn_pop_front(token_vec *v){
    token res = v->buf[v->head];
    v->size--;
    v->head = (v->head + 1) % v->cap;
    decrease_buf(v);
    return res;
}

bool tkn_is_empty(token_vec *v){
    return v->size == 0;
}

int tkn_get_size(token_vec *v){
    return v->size;
}

token tkn_get_el(token_vec *v, int idx){
    return v->buf[(v->head + idx) % v->cap];
}

void tkn_set_el(token_vec *v, int idx, token val){
    v->buf[(v->head + idx) % v->cap] = val;
}
