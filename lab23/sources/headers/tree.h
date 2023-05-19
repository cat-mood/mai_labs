#pragma once
#include <stdbool.h>

typedef struct node node;

struct node {
    double val;
    node *left;
    node *right;
};

typedef node* tree;

bool is_empty(tree t);
tree empty_tree();
tree build_tree(double val, tree l, tree r);
double root_val(tree t);
tree left(tree t);
tree right(tree t);
void destroy_root(tree t);