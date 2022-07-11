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

    print_ascii_tree(root);
}
