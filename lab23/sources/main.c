#include "headers/tree.h"
#include <stdio.h>
#include <string.h>

void add_menu(tree* t) {
    printf("Colors:\n");
    printf("1. Red\n");
    printf("2. Green\n");
    printf("3. Blue\n");
    printf("4. Yellow\n");
    printf("5. Purple\n");
    printf("6. Pink\n");
    printf("7. Orange\n");
    printf("8. White\n");
    printf("9. Black\n");
    printf("\nEnter color: ");
    color c;
    scanf("%d", &c);
    if (!add(t, c)) {
        printf("This color already added\n");
    }
}

void delete_menu(tree* t) {
    printf("Colors:\n");
    printf("1. Red\n");
    printf("2. Green\n");
    printf("3. Blue\n");
    printf("4. Yellow\n");
    printf("5. Purple\n");
    printf("6. Pink\n");
    printf("7. Orange\n");
    printf("8. White\n");
    printf("9. Black\n");
    printf("\nEnter color: ");
    color c;
    scanf("%d", &c);
    if (!delete(t, c)) {
        printf("There is no this color\n");
    }
}

void menu(tree* t) {
    int c;
    do {
        printf("Options: \n");
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Print degree\n");
        printf("4. Print tree\n");
        printf("5. Exit\n");
        printf("\nChoose option: ");
        scanf("%d", &c);
        if (c == 1) {
            printf("\n");
            add_menu(t);
        } else if (c == 2) {
            delete_menu(t);
        } else if (c == 3) {
            printf("Tree degree: %d\n", tree_degree(*t));
        } else if (c == 4) {
            print_tree(*t);
        }  else if (c == 5) {
            printf("Goodbye!\n");
        } else {
            printf("Wrong option!\n");
        }
    } while (c != 5);
}

int main() {
    tree t = empty_tree();
    menu(&t);
    
    return 0;
}