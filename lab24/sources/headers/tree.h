#pragma once
#include <stdbool.h>

typedef struct node node;

struct node {
    int val;
    node* left;
    node* right;
};

typedef node* tree;

bool is_empty_tree(tree t);
tree empty_tree();
tree build_tree(int val, tree l, tree r);
int root_val(tree t);
tree left(tree t);
tree right(tree t);
void destroy_root(tree t);
void print_tree(tree root);