#pragma once
#include <stdbool.h>
#include "expression.h"

typedef struct node node;

struct node {
    token val;
    node* left;
    node* right;
};

typedef node* tree;

bool is_empty_tree(tree t);
tree empty_tree();
tree build_tree(token val, tree l, tree r);
token root_val(tree t);
tree left(tree t);
tree right(tree t);
void destroy_root(tree t);
void print_tree(tree root);