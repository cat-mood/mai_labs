#include "headers/key.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    key k;
    char val[99];
} map;

bool read_keys(FILE* f, int n, map* m) {
    for (int i = 0; i < n; i++) {
        if (fread(&m[i].k, sizeof(key), 1, f) != 1) {
            return false;
        }
    }
    return true;
}

bool read_art(FILE* f, int n, map* m) {
    for (int i = 0; i < n; i++) {
        if (fread(&m[i].val, sizeof(char[99]), 1, f) != 1) {
            return false;
        }
    }
    return true;
}

void shell_sort(int n, map* m) {
    int i, j, step;
    map tmp;
    for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++) {
            tmp = m[i];
            for (j = i; j >= step; j -= step) {
                if (keycmp(tmp.k, m[j - step].k) < 0) {
                    m[j] = m[j - step];
                } else {
                    break;
                }
            }
            m[j] = tmp;
        }
    }
}

void print_art(FILE* art) {
    fseek(art, 0, SEEK_SET);
    char line[99];
    while (fread(line, sizeof(line), 1, art) == 1) {
        printf("%s\n", line);
    }
}

key get_key() {
    key k;
    scanf("%d%c", &k.num, &k.letter);
    return k;
}

int binary_search(key k, int n, map* m) {
    int mid = n / 2;
    int low = 0, high = n - 1;
    while (keycmp(m[mid].k, k) != 0 && low <= high) {
        if (keycmp(k, m[mid].k) > 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    if (low > high) {
        return -1;
    } else {
        return low;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    FILE* art = fopen(argv[1], "rb");
    if (art == NULL) {
        fprintf(stderr, "Can't open the second file!");
        return 2;
    }
    FILE* keys = fopen(argv[2], "rb");
    if (keys == NULL) {
        fprintf(stderr, "Can't open the first file!");
        return 2;
    }
    int n;
    if (fread(&n, sizeof(int), 1, keys) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 3;
    }
    map m[n];
    if (!read_keys(keys, n, m)) {
        fprintf(stderr, "Read elems error!\n");
        return 4;
    }
    if (!read_art(art, n, m)) {
        fprintf(stderr, "Read elems error!\n");
        return 4;
    }
    fclose(keys);
    fclose(art);
    shell_sort(n, m);
    for (int i = 0; i < n; i++) {
        printf("%s\n", m[i].val);
    }
    while (true) {
        printf("Enter key:\n");
        key user = get_key();
        int idx = binary_search(user, n, m);
        if (idx < 0) {
            printf("Key not found!\n");
        } else {
            printf("%s\n", m[idx].val);
        }
    }

    return 0;
}