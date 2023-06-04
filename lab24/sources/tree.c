#include "headers/tree.h"
#include <stdlib.h>
#include <stdio.h>

bool is_empty_tree(tree t){
    return (t == NULL);
}

tree empty_tree(){
    return NULL;
}

tree build_tree(int val, tree l, tree r){
    tree t = malloc(sizeof(node));
    t->val = val;
    t->left = l;
    t->right = r;
    return t;
}

int root_val(tree t){
    return t->val;
}

tree left(tree t){
    return t->left;
}

tree right(tree t){
    return t->right;
}

void destroy_root(tree t){
    free(t);
}

static void _print_tree(tree root, int n) {
    if (root == NULL) {
        return;
    }
    _print_tree(root->right, n + 1);    
    for (int i = 0; i < n; i++) {
        printf("\t");
    }
    printf("%s\n", root->val);
    _print_tree(root->left, n + 1);
}

void print_tree(tree root) {
    _print_tree(root, 1);
}