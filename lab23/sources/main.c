#include "headers/tree.h"
#include <stdio.h>
#include <string.h>

bool str_to_color(char* c, color* clr) {
    if (strcmp(c, "red") == 0) {
        *clr = RED;
    } else if (strcmp(c, "green") == 0) {
        *clr = GREEN;
    } else if (strcmp(c, "blue") == 0) {
        *clr = BLUE;
    } else if (strcmp(c, "yellow") == 0) {
        *clr = YELLOW;
    } else if (strcmp(c, "purple") == 0) {
        *clr = PURPLE;
    } else if (strcmp(c, "pink") == 0) {
        *clr = PINK;
    }  else if (strcmp(c, "orange") == 0) {
        *clr = ORANGE;
    } else if (strcmp(c, "white") == 0) {
        *clr = WHITE;
    } else if (strcmp(c, "black") == 0) {
        *clr = BLACK;
    } else {
        return false;
    }
    return true;
}

void add_menu(tree* t) {
    printf("Colors:\n");
    printf("red\n");
    printf("green\n");
    printf("blue\n");
    printf("yellow\n");
    printf("purple\n");
    printf("pink\n");
    printf("orange\n");
    printf("white\n");
    printf("black\n");
    printf("\nEnter color: ");
    char s[99];
    scanf("%s", s);
    color c;
    if (!str_to_color(s, &c)) {
        printf("Wrong color!\n");
    } else if (!add(t, c)) {
        printf("This color already added\n");
    }
}

void delete_menu(tree* t) {
    printf("Colors:\n");
    printf("red\n");
    printf("green\n");
    printf("blue\n");
    printf("yellow\n");
    printf("purple\n");
    printf("pink\n");
    printf("orange\n");
    printf("white\n");
    printf("black\n");
    printf("\nEnter color: ");
    char s[99];
    scanf("%s", s);
    color c;
    str_to_color(s, &c);
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
        c = getchar();
        if (c == '1') {
            printf("\n");
            add_menu(t);
        } else if (c == '2') {
            delete_menu(t);
        } else if (c == '3') {
            printf("Tree degree: %d\n", tree_degree(*t));
        } else if (c == '4') {
            print_tree(*t);
        }  else if (c == '5' || c == EOF) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Wrong option!\n");
        }
        while (c != '\n') {
            c = getchar();
        }
    } while (c != '5');
}

int main() {
    tree t = empty_tree();
    menu(&t);
    
    return 0;
}