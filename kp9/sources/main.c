#include "headers/key.h"
#include <stdbool.h>
#include <stdio.h>

bool read_keys(FILE* f, int n, key* k) {
    for (int i = 0; i < n; i++) {
        if (fread(&k[i], sizeof(key), 1, f) != 1) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 3){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    FILE* keys = fopen(argv[1], "rb");
    FILE* art = fopen(argv[2], "rb");
    int n;
    if (fread(&n, sizeof(int), 1, keys) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 1;
    }
    key k[n];
    if (!read_keys(keys, n, k)) {
        fprintf(stderr, "Read elems error!\n");
        return 2;
    }

    return 0;
}