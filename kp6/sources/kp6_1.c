#include <stdio.h>
#include <stdlib.h>
#include "headers/fields.h"

int main(int argc, char* argv[]){
    if (argc != 3){
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
    int chr;
    do {
        chr = fgetc(input);
        if (chr == EOF){
            fprintf(stderr, "Read error!\n");
            return 1;
        }
    } while (chr != '\n');
    comp c;
    int counter = 0;
    while (fscanf(input, "%[^;];%[^;];%d;%[^;];%d;%[^;];\n", c.surname, c.proc, &c.cores, c.video_type, &c.memory, c.os_name) == 6){
        if (fwrite(&c, sizeof(comp), 1, output) != 1){
            fprintf(stderr, "Write error!\n");
            return 1;
        }
        counter++;
    }
    // fseek(output, 0, SEEK_SET);     // pointer to top of file
    // if (fwrite(&counter, sizeof(int), 1, output) != 1) {
    //     fprintf(stderr, "Write error!\n");
    //     return 1;
    // }
    fclose(input);
    fclose(output);

    return 0;
}   