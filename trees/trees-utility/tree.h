#ifndef _TREE_H  
#define _TREE_H 

typedef int ET;
typedef struct AVLTreeNode *AVL;
struct AVLTreeNode {
    AVL Left;
    AVL Right;
    ET Element;
    int Height;
};

#endif 
