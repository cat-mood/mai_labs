#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 5){
        fprintf(stderr, "Wrong number of args!\n");
        return 1;
    }
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "wb");
    if (input == NULL){
        fprintf(stderr, "Can't open input file!\n");
        return 1;
    }
    if (output == NULL){
        fprintf(stderr, "Can't create output file!\n");
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
        fprintf(stderr, "Can't open input file!\n");
        return 1;
    }
    if (output == NULL){
        fprintf(stderr, "Can't create output file!\n");
        return 1;
    }
    char key[4];
    counter = 0;
    while (fscanf(input, "%s\n", key) == 1){
        if (fwrite(key, sizeof(key), 1, output) != 1){
            fprintf(stderr, "Write error!\n");
            return 1;
        }
        counter++;
    }
    printf("%d lines are written from %s\n", counter, argv[3]);
    fclose(input);
    fclose(output);

    return 0;
}