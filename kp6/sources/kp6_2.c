#include <stdio.h>
#include "headers/fields.h"
#include <stdbool.h>
#include <string.h>

bool is_same(comp c1, comp c2){
    return strcmp(c1.surname, c2.surname) == 0 && strcmp(c1.proc, c2.proc) == 0 && strcmp(c1.video_type, c2.video_type) == 0 && c1.memory == c2.memory && c1.cores == c2.cores && strcmp(c1.os_name, c2.os_name) == 0;
}


int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL){
        fprintf(stderr, "Can't open file!\n");
        return 1;
    }
    int n;
    if (fread(&n, sizeof(int), 1, file) != 1) {
        fprintf(stderr, "Read number of elems error!\n");
        return 1;
    }
    comp c1;
    comp c2;
    fseek(file, sizeof(int), SEEK_SET);
    for (int i = 0; i < n - 1; i++) {
        if (fread(&c1, sizeof(comp), 1, file) != 1) {
            fprintf(stderr, "Read elem error!\n");
            return 1;
        }
        for (int j = i + 1; j < n; j++) {
            if (fread(&c2, sizeof(comp), 1, file) != 1) {
                fprintf(stderr, "Read elem error!\n");
                return 1;
            }
            if (is_same(c1, c2)) {
                printf("%s\n", c1.surname);
            }
        }
        fseek(file, sizeof(int) + sizeof(comp) * i, SEEK_SET);
    }
    return 0;
}