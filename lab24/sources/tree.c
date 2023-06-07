#include "headers/tree.h"
#include <stdlib.h>
#include <stdio.h>

bool is_empty_tree(tree t){
    return (t == NULL);
}

tree empty_tree(){
    return NULL;
}

tree build_tree(token val, tree l, tree r){
    tree t = malloc(sizeof(node));
    t->val = val;
    t->left = l;
    t->right = r;
    return t;
}

token root_val(tree t){
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

static void print_token(token t) {
    if (t.type == TOKEN_VAR_NAME) {
        printf("%s", t.var_name);
    } else if (t.type == TOKEN_CONST) {
        printf("%lf", t.cnst);
    } else if (t.type == TOKEN_OPER) {
        printf("%c", t.oper);
    } else if (t.type == TOKEN_BR_L) {
        printf("(");
    } else if (t.type == TOKEN_BR_R) {
        printf(")");
    }
}

static void _print_tree(tree root, int n) {
    if (root == NULL) {
        return;
    }
    _print_tree(root->right, n + 1);    
    for (int i = 0; i < n; i++) {
        printf("\t");
    }
    print_token(root->val);
    printf("\n");
    _print_tree(root->left, n + 1);
}

void print_tree(tree root) {
    _print_tree(root, 1);
}