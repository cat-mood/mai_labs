#include <stdio.h>
#include <ctype.h>
#include "headers/dbl_vec.h"

int input_matr(dbl_vec* CIP, dbl_vec* PI, dbl_vec* YE){
    int width = 0, c = getchar();
    int num = 0, column = 0, not_zeros = 0;
    while (c != EOF){
        if (c == ' '){
            if (num != 0){
                push_back(YE, num);
                push_back(PI, column);
                not_zeros++;
            }
            // как-то надо определить первый элекмент в линии: длина всего вектора PI - количество элементов в текущей строке
            column++;
            num = 0;
        } else if (c == '\n' || c == EOF) {
            if (num != 0){
                push_back(YE, num);
                push_back(PI, column);
                not_zeros++;
            }
            // if (not_zeros == 0) {
            //     push_back(CIP, -1);
            // } else {
            push_back(CIP, get_size(PI) - not_zeros);
            // }
            not_zeros = 0;
            column++;
            if (column > width) {
                width = column;
            }
            column = 0;
            num = 0;
        } else if (!isdigit(c)){
            fprintf(stderr, "Not number was inputed!\n");
            return -1;
        } else {
            num *= 10;
            num += c - '0';
        }

        c = getchar();
    }
    return width;
}

void print_zeros(int n){
    if (n == 0){
        return;
    }
    for (int i = 0; i < n; i++){
        printf("0 ");
    }
}

void print_matr(dbl_vec* CIP, dbl_vec* PI, dbl_vec* YE, int width){
    int idx_line = 0, column = 0;
    for (int i = 0; i < get_size(PI); i++){
        // printf("    DEBUG: i = %d  idx_line = %d    ", i, idx_line);
        if (i == get_el(CIP, idx_line)){
            if (column != width && i != 0){
                print_zeros(width - column);
            }
            printf("\n");
            idx_line++;
            if (get_el(CIP, idx_line - 1) == get_el(CIP, idx_line)) {
                print_zeros(width);
                printf("\n");
                idx_line++;
            }
            column = 0;
        } 
        // if (get_el(CIP, idx_line) == get_el(CIP, idx_line + 1)){
        //     print_zeros(width);
        //     printf("\n");
        //     idx_line++;
        //     column = 0;
        // }
        if (get_el(PI, i) > column) {
            print_zeros(get_el(PI, i) - column);
            column = get_el(PI, i);
        }
        printf("%d ", get_el(YE, i));
        column++;
    }
    print_zeros(width - column);
    printf("\n");
    // printf("width: %d\n", width);
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// return el's idx in PI or YE
int abs_max(dbl_vec* YE) {
    int max = 0, idx_max, preidx_max;
    bool is_same_exist = false;
    for (int i = 0; i < get_size(YE); i++) {
        if (abs(get_el(YE, i)) > max) {
            max = abs(get_el(YE, i));
            idx_max = i;
            is_same_exist = false;
        } else if (abs(get_el(YE, i)) == max) {
            preidx_max = idx_max;
            idx_max = i;
            is_same_exist = true;
        }
    }
    if (is_same_exist) {
        return preidx_max;
    }
    return idx_max;
}

void divide_column(dbl_vec* PI, dbl_vec* YE, int column, int val) {
    for (int i = 0; i < get_size(PI); i++) {
        if (get_el(PI, i) == column) {
            set_el(YE, i, get_el(YE, i) / val);
        }
    }
}

int main(){
    dbl_vec CIP = init();
    dbl_vec PI = init();
    dbl_vec YE = init();
    int width = input_matr(&CIP, &PI, &YE);
    if (width == -1){
        return 1;
    }
    printf("CIP:\n");
    for (int i = 0; i < get_size(&CIP); i++){
        printf("%d\n", get_el(&CIP, i));
    }
    printf("PI:\n");
    for (int i = 0; i < get_size(&PI); i++){
        printf("%d\n", get_el(&PI, i));
    }
    printf("YE:\n");
    for (int i = 0; i < get_size(&YE); i++){
        printf("%d\n", get_el(&YE, i));
    }

    printf("Matrix:\n");
    print_matr(&CIP, &PI, &YE, width);
    printf("\n");
    int idx_max = abs_max(&YE);
    int max_column = get_el(&PI, idx_max);
    divide_column(&PI, &YE, max_column, get_el(&YE, idx_max));
    printf("Divided matrix:\n");
    print_matr(&CIP, &PI, &YE, width);
    
    destroy(&CIP);
    destroy(&PI);
    destroy(&YE);

    return 0;
}