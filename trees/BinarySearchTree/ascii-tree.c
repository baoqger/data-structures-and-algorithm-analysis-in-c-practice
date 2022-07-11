#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "ascii-tree.h"

struct AsciiNode {
    AsciiTree left;
    AsciiTree right;
    int edge_length; // length of the edge from this node to its child
    int height;
    int lablen; // length of node label
    int parent_dir; // -1 = I am left, 0 = I am root, 1 = I am right
    char label[11]; //max supported unit32 in dec, 10 digits max
};

#define MAX_HEIGHT 1000
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
#define INFINITY (1 << 20);

// adjust the gap between left and right nodes
int gap = 5;

// used for printing next node in the same level,
// this is the x coordinate of  the next char printed
int print_next;

int MIN(int X, int Y) {
    return ((X) < (Y) ? (X) : (Y));
}

int MAX(int X, int Y) {
    return ((X) > (Y) ? (X) : (Y));
}

AsciiTree build_ascii_tree_recursive(BST t) 
{
  AsciiTree node;
  
  if (t == NULL) return NULL;

  node = malloc(sizeof(struct AsciiNode));
  node->left = build_ascii_tree_recursive(leftChild(t));
  node->right = build_ascii_tree_recursive(rightChild(t));
  
  if (node->left != NULL) 
  {
    node->left->parent_dir = -1;
  }

  if (node->right != NULL) 
  {
    node->right->parent_dir = 1;
  }

  sprintf(node->label, "%d", retrieve(t));
  node->lablen = strlen(node->label);

  return node;
}


// copy the tree into  the ascii node structure
AsciiTree build_ascii_tree(BST t) {
    AsciiTree node;
    if(t == NULL) {
        return NULL;
    }

    node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}

// Free all the nodes of the give free
void free_ascii_tree(AsciiTree node){
    if(node == NULL) {
        return;
    }
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    free(node);
}

// the following function fills in the lprofile array for the given tree
// it assumes that the center of the label of the root of this tree 
// is located at a position(x,y). 
// It assumes that the edge_length fields have been computed for this tree
void compute_lprofile(AsciiTree node, int x, int y) 
{
  int i, isleft;
  if (node == NULL) return;
  isleft = (node->parent_dir == -1);
  lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
  if (node->left != NULL) 
  {
	  for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) 
    {
	    lprofile[y+i] = MIN(lprofile[y+i], x-i);
    }
  }
  compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
  compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

void compute_rprofile(AsciiTree node, int x, int y) 
{
  int i, notleft;
  if (node == NULL) return;
  notleft = (node->parent_dir != -1);
  rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
  if (node->right != NULL) 
  {
	  for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) 
    {
	    rprofile[y+i] = MAX(rprofile[y+i], x+i);
    }
  }
  compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
  compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

//This function fills in the edge_length and 
//height fields of the specified tree
void compute_edge_lengths(AsciiTree node) 
{
  int h, hmin, i, delta;
  if (node == NULL) return;
  compute_edge_lengths(node->left);
  compute_edge_lengths(node->right);

  /* first fill in the edge_length of node */
  if (node->right == NULL && node->left == NULL) {
	  node->edge_length = 0; // edge length of leaf node is zero
  } 
  else {
    if (node->left != NULL) {
	    for (i=0; i<node->left->height && i < MAX_HEIGHT; i++) {
		    rprofile[i] = -INFINITY;
	    }
	    compute_rprofile(node->left, 0, 0);
	    hmin = node->left->height;
    } else {
	    hmin = 0;
    }
	if (node->right != NULL) 
    {
	    for (i=0; i<node->right->height && i < MAX_HEIGHT; i++) {
		    lprofile[i] = INFINITY;
	    }
	    compute_lprofile(node->right, 0, 0);
	    hmin = MIN(node->right->height, hmin);
    } else {
	    hmin = 0;
    }
	delta = 4;
	for (i=0; i<hmin; i++) {
	    delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
    }
	  
    //If the node has two children of height 1, then we allow the
    //two leaves to be within 1, instead of 2 
	if (((node->left != NULL && node->left->height == 1) ||
	      (node->right != NULL && node->right->height == 1))&&delta>4) {
      delta--;
    }
	    
    node->edge_length = ((delta+1)/2) - 1;
  }

  //now fill in the height of node
  h = 1; // height of leaf  node is 1
  if (node->left != NULL) 
  {
	  h = MAX(node->left->height + node->edge_length + 1, h); // height of node equals to the height of child + the edge_length of the node
  }
  if (node->right != NULL) 
  {
	  h = MAX(node->right->height + node->edge_length + 1, h);
  }
  node->height = h;
}

//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(AsciiTree node, int x, int level) 
{
  int i, isleft;
  if (node == NULL) return;
  isleft = (node->parent_dir == -1);
  if (level == 0) { // print root node
    for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++) {
	    printf(" ");
    }
	print_next += i;
	printf("%s", node->label);
	print_next += node->lablen;
  
  } else if (node->edge_length >= level) { // print the edge
	  if (node->left != NULL) {
	    for (i=0; i<(x-print_next-(level)); i++) {
		    printf(" ");
	    }
	    print_next += i;
	    printf("/");
	    print_next++;
      }
	  if (node->right != NULL) {
	    for (i=0; i<(x-print_next+(level)); i++) {
		    printf(" ");
	    }
	    print_next += i;
	    printf("\\"); // escape 
	    print_next++;
    }
  } else {
	  print_level(node->left, 
                x - node->edge_length -  1, 
                level - node->edge_length - 1);
	  print_level(node->right, 
                x+node->edge_length+1, 
                level-node->edge_length-1);
  }
}

//prints ascii tree for given Tree structure
void print_ascii_tree(BST t) 
{
  AsciiTree proot;
  int xmin, i;
  if (t == NULL) return;
  proot = build_ascii_tree(t);
  compute_edge_lengths(proot);
  for (i=0; i<proot->height && i < MAX_HEIGHT; i++) 
  {
	  lprofile[i] = INFINITY; // initialize lprofile[]
  }
  compute_lprofile(proot, 0, 0); // compute lprofile[]
  xmin = 0;
  for (i = 0; i < proot->height && i < MAX_HEIGHT; i++) 
  {
	  xmin = MIN(xmin, lprofile[i]); // get the minimum of lprofile[]
  }
  for (i = 0; i < proot->height; i++) // print the tree by value 
  {
	  print_next = 0;
	  print_level(proot, -xmin, i);
	  printf("\n");
  }
  if (proot->height >= MAX_HEIGHT) 
  {
	  printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
  }
  free_ascii_tree(proot); 
}


