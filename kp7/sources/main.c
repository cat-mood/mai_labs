#include <stdio.h>
#include <ctype.h>
#include "headers/dbl_vec.h"

typedef struct {
    dbl_vec* CIP;   // idx of first el in PI and YE
    dbl_vec* PI;    // numbers of column
    dbl_vec* YE;    // numbers
    int width;  // number of columns
    int lines;
} matrix;

void input_matr(matrix* m){
    m->width = 0;
    m->lines = 0;
    int c = getchar();
    int num = 0, column = 0, not_zeros = 0;
    bool is_negative = false;
    while (c != EOF){
        if (c == ' '){
            if (num != 0){
                if (is_negative) {
                    num *= -1;
                }
                push_back(m->YE, num);
                push_back(m->PI, column);
                not_zeros++;
            }
            // как-то надо определить первый элекмент в линии: длина всего вектора PI - количество элементов в текущей строке
            column++;
            num = 0;
            is_negative = false;
        } else if (c == '\n' || c == EOF) {
            if (num != 0){
                if (is_negative) {
                    num *= -1;
                }
                push_back(m->YE, num);
                push_back(m->PI, column);
                not_zeros++;
            }
            push_back(m->CIP, get_size(m->PI) - not_zeros);
            not_zeros = 0;
            column++;
            if (column > m->width) {
                m->width = column;
            }
            column = 0;
            num = 0;
            is_negative = false;
            m->lines++;
        } else if (c == '-') {
            is_negative = true;
        } else if (!isdigit(c)){
            fprintf(stderr, "Not number was inputed!\n");
            m->width = -1;
            return;
        } else {
            num *= 10;
            num += c - '0';
        }

        c = getchar();
    }
}

void print_zeros(int n){
    if (n == 0){
        return;
    }
    for (int i = 0; i < n; i++){
        printf("0 ");
    }
}

void print_matr(matrix m){
    int idx_line = 0, column = 0;
    for (int i = 0; i < get_size(m.PI); i++){
        // printf("    DEBUG: i = %d  idx_line = %d    ", i, idx_line);
        if (i == get_el(m.CIP, idx_line)){
            if (column != m.width && i != 0){
                print_zeros(m.width - column);
            }
            printf("\n");
            idx_line++;
            if (get_el(m.CIP, idx_line - 1) == get_el(m.CIP, idx_line)) {
                print_zeros(m.width);
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
        if (get_el(m.PI, i) > column) {
            print_zeros(get_el(m.PI, i) - column);
            column = get_el(m.PI, i);
        }
        printf("%d ", get_el(m.YE, i));
        column++;
    }
    print_zeros(m.width - column);
    printf("\n");
    for (int i = 0; i < m.lines - idx_line; i++) {
        print_zeros(m.width);
        printf("\n");
    }
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
int abs_max(matrix m) {
    int max = 0, idx_max, preidx_max;
    bool is_same_exist = false;
    for (int i = 0; i < get_size(m.YE); i++) {
        if (abs(get_el(m.YE, i)) > max) {
            max = abs(get_el(m.YE, i));
            idx_max = i;
            is_same_exist = false;
        } else if (abs(get_el(m.YE, i)) == max) {
            if (get_el(m.PI, i) > get_el(m.PI, idx_max)) {
                preidx_max = idx_max;
            } else {
                preidx_max = i;
            }
            idx_max = i;
            is_same_exist = true;
        }
    }
    if (is_same_exist) {
        return preidx_max;
    }
    return idx_max;
}

// void clean_zeros(matrix m) {
//     for (int i = 0; i < get_size(m.YE); i++) {
//         if (get_el(m.YE, i) == 0) {

//         }
//     }
// }

void divide_column(matrix m, int column, int val) {
    for (int i = 0; i < get_size(m.PI); i++) {
        if (get_el(m.PI, i) == column) {
            set_el(m.YE, i, get_el(m.YE, i) / val);
        }
    }
}


int main(){
    matrix m;
    dbl_vec CIP = init();
    dbl_vec PI = init();
    dbl_vec YE = init();
    m.CIP = &CIP;
    m.PI = &PI;
    m.YE = &YE;
    input_matr(&m);
    if (m.width == -1){
        return 1;
    }
    printf("CIP:\n");
    for (int i = 0; i < get_size(m.CIP); i++){
        printf("%d\n", get_el(&CIP, i));
    }
    printf("PI:\n");
    for (int i = 0; i < get_size(m.PI); i++){
        printf("%d\n", get_el(&PI, i));
    }
    printf("YE:\n");
    for (int i = 0; i < get_size(m.YE); i++){
        printf("%d\n", get_el(&YE, i));
    }

    printf("Matrix:\n");
    print_matr(m);
    printf("\n");
    int idx_max = abs_max(m);
    int max_column = get_el(m.PI, idx_max);
    divide_column(m, max_column, get_el(m.YE, idx_max));
    printf("Divided matrix:\n");
    print_matr(m);
    
    destroy(m.CIP);
    destroy(m.PI);
    destroy(m.YE);

    return 0;
}
