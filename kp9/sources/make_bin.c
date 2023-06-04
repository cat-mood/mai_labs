#include <stdio.h>
#include <stdlib.h>
#include "headers/key.h"

int main(int argc, char* argv[]){
    if (argc != 5){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "wb");
    if (input == NULL){
        fprintf(stderr, "Can't open the first input file!\n");
        return 1;
    }
    if (output == NULL){
        fprintf(stderr, "Can't create the first output file!\n");
        return 1;
    }
    char line[99];
    int counter = 0;
    while (fscanf(input, "%[^\n]\n", line) == 1){
        if (fwrite(line, sizeof(line), 1, output) != 1){
            fprintf(stderr, "Write error!\n");
            return 1;
        }
        counter++;
    }
    printf("%d lines are written from %s\n", counter, argv[1]);
    fclose(input);
    fclose(output);

    input = fopen(argv[3], "r");
    output = fopen(argv[4], "wb");
    if (input == NULL){
        fprintf(stderr, "Can't open the second input file!\n");
        return 1;
    }
    if (output == NULL){
        fprintf(stderr, "Can't create the second output file!\n");
        return 1;
    }
    key k;
    counter = 0;
    fseek(output, sizeof(int), SEEK_SET);
    while (fscanf(input, "%d%c\n", &k.num, &k.letter) == 2){
        if (fwrite(&k, sizeof(key), 1, output) != 1){
            fprintf(stderr, "Write error!\n");
            return 1;
        }
        counter++;
    }
    fseek(output, 0, SEEK_SET);
    if (fwrite(&counter, sizeof(int), 1, output) != 1){
        fprintf(stderr, "Write error!\n");
        return 1;
    }
    printf("%d lines are written from %s\n", counter, argv[3]);
    fclose(input);
    fclose(output);

    return 0;
}