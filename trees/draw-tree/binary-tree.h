#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H


typedef int ET;
typedef struct TreeNode *Position;
typedef struct TreeNode *Tree;
struct TreeNode {
    Tree left;
    Tree right;
    ET element;
};
Tree make_empty(Tree);
Position find_min(Tree);
Position find_max(Tree);
Position find(ET, Tree);
Tree insert(ET, Tree);
Tree deleteNode(ET, Tree);

#endif 
