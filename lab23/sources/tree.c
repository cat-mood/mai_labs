#include "headers/tree.h"
#include <stdlib.h>

bool is_empty(tree t){
    return (t == NULL);
}

tree empty_tree(){
    return NULL;
}

tree build_tree(double val, tree l, tree r){
    node *t = malloc(sizeof(node));
    t->val = val;
    t->left = l;
    t->right = r;
    return t;
}

double root_val(tree t){
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

tree* find(tree *t, double val){
    if (*t == NULL){
        return t;
    }
    if (val == (*t)->val){
        return t;
    } else if (val < (*t)->val){
        return find(&((*t)->left), val);
    } else {
        return find(&((*t)->right), val);
    }
}

bool add(tree *t, double val){
    tree *place = find(t, val);
    if (*place != NULL){
        return false;
    } 
    tree new_node = malloc(sizeof(node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    *place = new_node;
    return true;
}

bool delete(tree *t, double val){
    tree *place = find(t, val);
    if (*place == NULL) {
        return false;
    }
    if ((*place)->left == NULL && (*place)->right == NULL){
        free(*place);

    } else if ((*place)->left == NULL){
        tree new_right = (*place)->right;
        free(*place);
        *place = new_right;   
    } else if ((*place)->right == NULL){
        tree new_left = (*place)->left;
        free(*place);
        *place = new_left;
    } else {
        tree *r = &((*place)->right);
        while ((*r)->left != NULL){
            r = &((*r)->left);
            tree min_r = (*r);
            *r = (*r)->right;
            min_r->right = (*place)->right;
            min_r->left = (*place)->left;
            free(*place);
            *place = min_r;
        }
    }
    return true;
}
