#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"


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
    if(t == NULL) {
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

Tree insert(ET value, Tree t)  {
    Position new_node;
    if (t == NULL) {
        new_node = malloc(sizeof(struct TreeNode));
        if(new_node == NULL) {
            fprintf(stderr, "failed to allocate memory.\n");
        }
        new_node->element = value;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (value < t->element) {
        t->left = insert(value, t->left);
    } else if (value > t->element) {
        t->right = insert(value, t->right);
    }
    // when the value is duplicated, do nothing
    return t;
}

Tree deleteNode(ET value, Tree t) {
    Tree tmp;
    if(t == NULL) return NULL;
    if(value < t->element) {
        t->left = deleteNode(value, t->left);
    } else if(value > t->element) {
        t->right = deleteNode(value, t->right);
    } // node is found 
    else if(t->left && t->right) { // the node has both left and right child
       tmp = find_min(t->right);
       t->element = tmp->element;
       t->right = deleteNode(t->element, t->right);
    } else { // the node has zero or one  child
        tmp = t;
        if(t->left == NULL) {
            t = t->right;
        } 
        else if(t->right == NULL) {
            t = t->left;
        }
        free(tmp);
    }
    return t;
}
