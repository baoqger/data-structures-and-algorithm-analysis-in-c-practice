#include <stdio.h>
#include <stdlib.h>
#include "binary-tree.h"
#include "ascii-tree.h"

int main() {
    Tree root = NULL;
    make_empty(root);
    root = insert(10, root);
    root = insert(9, root);
    root = insert(11, root);
    root = insert(11, root);
    root = insert(100, root);
    root = insert(1, root);
    root = insert(18, root);
    root = insert(2, root);
    root = insert(34, root);
    root = insert(15, root);
    root = insert(7, root);
    root = insert(6, root);
    root = insert(14, root);
    root = insert(13, root);
    root = insert(12, root);
    root = insert(8, root);

    print_ascii_tree(root);
}
