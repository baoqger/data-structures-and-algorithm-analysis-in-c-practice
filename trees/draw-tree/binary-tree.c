#include "binary-tree.h"

struct TreeNode {
    Position left;
    Position right;
    ET element;
};

Tree make_empty(Tree t) {
    if (t != NULL) {
        make_empty(t->left);
        make_empty(t->right);
        free(t);          
    }
    return NULL;
}

Position find_min(Tree t) {
    if(t == NULL) { // when root node is NULL
        return NULL;
    } else if(t->left == NULL) {
        return t;
    } else {
        return find_min(t->left);
    }
}

Position find_max(Tree t) {
    if(t == NULL) {
        return t;
    } else if(t->right == NULL) {
        return t;
    } else {
        return find_max(t->right);
    }
}

Position find(ET elem, Tree t) {
    if(Tree == NULL) {
        return NULL;
    } 
    if ( elem == t->element) {
        return t;
    } else if(elem < t->element ) {
        return find(elem, t->left);
    } else {
        return find(elem, t->right);
    }
}
