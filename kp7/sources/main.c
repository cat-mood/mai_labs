#include <stdio.h>
#include <ctype.h>
#include "headers/dbl_vec.h"

bool input_matr(dbl_vec* CIP, dbl_vec* PI, dbl_vec* YE){
    int c = getchar();
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
            if (not_zeros == 0) {
                push_back(CIP, -1);
            } else {
                push_back(CIP, get_size(PI) - not_zeros);
            }
            not_zeros = 0;
            column = 0;
            num = 0;
        } else if (!isdigit(c)){
            fprintf(stderr, "Not number was inputed!\n");
            return false;
        } else {
            num *= 10;
            num += c - '0';
        }

        c = getchar();
    }
    return true;
}

int main(){
    dbl_vec CIP = init();
    dbl_vec PI = init();
    dbl_vec YE = init();
    if (!input_matr(&CIP, &PI, &YE)){
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

    return 0;
}