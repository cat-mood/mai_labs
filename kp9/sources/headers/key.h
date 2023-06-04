#pragma once

typedef struct {
    int num;
    char letter;
} key;

int keycmp(key k1, key k2);
