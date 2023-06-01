#pragma once
#include <stdbool.h>

typedef enum {
    RED = 1,
    GREEN,
    BLUE,
    YELLOW,
    PURPLE,
    PINK,
    ORANGE,
    WHITE,
    BLACK
} color;

typedef struct node node;

struct node {
    color val;
    node* left;
    node* right;
};

typedef node* tree;

bool is_empty(tree t);
tree empty_tree();
tree build_tree(color val, tree l, tree r);
color root_val(tree t);
tree left(tree t);
tree right(tree t);
void destroy_root(tree t);
bool add(tree* t, color val);
bool delete(tree* t, color val);
int tree_degree(tree t);
void print_tree(tree root);