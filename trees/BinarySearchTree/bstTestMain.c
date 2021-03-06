#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ascii-tree.h"

void generate_dot(BST);
void delete_tree(BST);
void test_initializeBST();
void test_find();
void test_findMinBST();
void test_findMaxBST();
void test_insert();
void test_delete();
void test_numNodes();
void test_numLeaves();
void test_numFullNodes();
void test_randBST();
void test_genTrees();
void test_perfectBST();
void test_printRangeKeys();
void test_levelOrder();
void test_similar();
void test_same();
void test_inorderTraversal();
void test_diameterOfBST();
void verify_deleteLeafNode();
void test_heightOfBST();
int
main()
{
  printf("///////////////////////\n");
  printf("// BINARY SEARCH TREE TEST\n");
  printf("///////////////////////\n\n");
  
  test_initializeBST();
  verify_deleteLeafNode();
  test_find();              printf("\n");
  test_findMinBST();           printf("\n");
  test_findMaxBST();           printf("\n");
  test_insert();
  test_delete();
  test_numNodes();          printf("\n");
  test_numLeaves();         printf("\n");
  test_numFullNodes();      printf("\n");
  test_randBST();           printf("\n");
  test_genTrees();          printf("\n");
  test_perfectBST();        printf("\n");
  test_printRangeKeys();    printf("\n\n");
  test_levelOrder();        printf("\n\n");
  test_similar();           printf("\n\n");
  test_same();              printf("\n\n");
  test_inorderTraversal();  printf("\n\n");
  test_diameterOfBST();     printf("\n\n");
  test_heightOfBST();       printf("\n\n");
  return 0;
}


void
generate_dot(BST T)
{
  char* dotFilename = "bst.dot";
  FILE *fp = fopen(dotFilename,"w");
  bst_print_dot(T,fp);
  fclose(fp);
  printFile(dotFilename);
}

void
delete_tree(BST T)
{
  T = makeEmpty(T);
  free(T);
}  

void 
verify_deleteLeafNode() {
    printf("Test: delete leaf node\n");
    ET test_array[] = {2, 1, 3};
    BST T = initializeBST(test_array, 3);
    print_ascii_tree(T);
    delete(1, T);
    printf("Delete node 1.\n");
    print_ascii_tree(T);
    delete_tree(T);    
}

void
test_initializeBST()
{
  printf("TEST: initializeBST\n");
  ET test_array[] = {2,1,3,4,5};
  BST T = initializeBST(test_array, 5);
  print_ascii_tree(T);
  // generate_dot(T);
  delete_tree(T);
}

void
test_find()
{
  printf("TEST: find\n");
  ET test_array[] = {2,1,3};
  BST T = initializeBST(test_array, 3);
  int target = 1;
  printf("want to find the element: %d\n", target);
  Position pos = find(target, T);
  printf("Found the element: %d\n", retrieve(pos));
  delete_tree(T);
}

void
test_findMinBST()
{
  printf("TEST: findMinBST\n");
  ET test_array[] = {2,1,3,5,0};
  BST T = initializeBST(test_array, 5);
  Position pos = findMinBST(T);
  printf("The min element in the tree: %d\n", retrieve(pos));
  Position pos2 = findMinBST_iterative(T);
  printf("The min element in the tree(iterative): %d\n", retrieve(pos2));
  delete_tree(T);
}  

void
test_findMaxBST()
{
  printf("TEST: findMaxBST\n");
  ET test_array[] = {2,1,3};
  BST T = initializeBST(test_array, 3);
  Position pos = findMaxBST(T);
  printf("The max element in the tree: %d\n", retrieve(pos));
  Position pos2 = findMaxBST_iterative(T);
  printf("The max element in the tree(iterative): %d\n", retrieve(pos2));

  delete_tree(T);
}  
  
void
test_insert()
{
  printf("TEST: insert\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  printf("Initial tree\n");
  print_ascii_tree(T);
  T = insert(10, T);
  printf("After insertion.\n");
  print_ascii_tree(T);
  delete_tree(T);  
}

void
test_delete()
{
  printf("TEST: delete\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  printf("Initial Tree.\n");
  print_ascii_tree(T);
  printf("deleting the root: %d\n", 3);
  T = delete(3, T);
  print_ascii_tree(T);
  delete_tree(T);  
}

void
test_numNodes()
{
  printf("TEST: numNodes\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  print_ascii_tree(T);
  printf("num of nodes in the tree: %d\n", numNodes(T));
  printf("num of nodes in the tree(solution 2): %d\n", numNodes2(T));
  delete_tree(T);
}

void
test_numLeaves()
{
  printf("TEST: numLeaves\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  print_ascii_tree(T);
  printf("num of leaves in the tree: %d\n", numLeaves(T));
  printf("num of leaves in the tree(second solution): %d\n", numLeaves2(T));
  delete_tree(T);
}

void
test_numFullNodes()
{
  printf("TEST: numFullNodes\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  print_ascii_tree(T);
  printf("num of full nodes in the tree: %d\n", numFullNodes(T));
  printf("num of full nodes in the tree(second solution): %d\n", numFullNodes2(T));
  delete_tree(T);
}

void
test_randBST()
{
  printf("TEST: randBST\n");
  BST T = randBST(20);
  print_ascii_tree(T);
  delete_tree(T);
}

void test_genTrees() {
    printf("Test: genTrees\n");
    int b = 2;
    int *a = NULL; 
    a = &b;
    BST T = genTrees(3, a);
    print_ascii_tree(T);
    delete_tree(T);
}

void
test_perfectBST()
{
  printf("TEST: perfectBST\n");
  BST T = perfectBST(3);
  print_ascii_tree(T);
  delete_tree(T);
}

void
test_printRangeKeys()
{
  printf("TEST: printRangeKeys\n");
  BST T = perfectBST(2);
  generate_dot(T);
  int k1 = 0;
  int k2 = 3;
  printf("range between k1: %d and k2: %d\n", k1, k2);
  printRangeKeys(T, k1, k2);
  delete_tree(T);  
}

void
test_levelOrder()
{
  printf("TEST: levelOrder\n");
  BST T = perfectBST(2);
  print_ascii_tree(T);
  printf("print node in level order\n");
  levelOrder(T);
  delete_tree(T);
}

void
test_similar()
{
  printf("TEST: similar\n");
  // BST T_similar1 = perfectBST(2);
  // BST T_similar2 = perfectBST(2);
  // BST T_diff1 = perfectBST(3);
  ET arr1[] = {2, 1 ,3};
  ET arr2[] = {2 ,3, 1};
  ET arr3[] = {1, 2, 3};
  BST T1 = initializeBST(arr1, 3);
  BST T2 = initializeBST(arr2, 3);
  BST T3 = initializeBST(arr3, 3);
  printf("T1\n");
  print_ascii_tree(T1);
  printf("T2\n");
  print_ascii_tree(T2);
  printf("T3\n");
  print_ascii_tree(T3);
  assert(similar(T1, T2) == 1);
  assert(similar(T1, T3) == 0);
  printf("All pass");
  delete_tree(T1);
  delete_tree(T2);
  delete_tree(T3);
}

void
test_same()
{
  printf("TEST: same\n");
  BST T1 = perfectBST(2);
  BST T2 = perfectBST(3);
  assert(same(T1, T1) == 0);
  assert(same(T1, T2) != 0);
  printf("All pass");
  delete_tree(T1);
  delete_tree(T2);
}

void
test_inorderTraversal()
{
  printf("TEST: inorderTraversal\n");
  ET test_array[] = {3,1,4,2,5};
  BST T = initializeBST(test_array, 5);
  print_ascii_tree(T);
  printf("inorder traversal: \n");
  int arrayLength;
  ET* array = inorderTraversal(T, &arrayLength);
  printArray(array, arrayLength);
}

void
test_diameterOfBST()
{
  printf("TEST: diameterOfBST\n");
  ET test_array[] = {3,1,4};
  BST T = initializeBST(test_array, 3);
  printf("max diameter: %d\n", diameterOfBST(T));
}

void test_heightOfBST() {
    printf("TEST: heightOfBST\n");
    ET test_array[] = {3, 1, 4, 2, 5};
    BST T1 = initializeBST(test_array, 5);
    print_ascii_tree(T1);
    printf("Height of this tree is : %d\n", heightOfBST(T1));

    ET test_array2[] = {1, 2, 3, 4, 5};
    BST T2 = initializeBST(test_array2, 5);
    print_ascii_tree(T2);
    printf("Height of this tree is : %d\n", heightOfBST(T2));
    delete_tree(T1);
    delete_tree(T2);
}
