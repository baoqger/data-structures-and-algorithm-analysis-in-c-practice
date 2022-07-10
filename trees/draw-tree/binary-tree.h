#include <stdio.h>

typedef int ET;
struct TreeNode;
typedef struct TreeNode *Position;
typedef Position Tree;
Tree make_empty(Tree);
Position find_min(Tree);
Position find_max(Tree);
Position find(Tree);
