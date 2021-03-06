/* Project 7: Binary Search Tree
Nick Crepeau 
Cody Wood 
Ethan Rocheleau 
Nate Johnson
*/

#ifndef binaryTree_H
#define binaryTree_H
#include <stdbool.h>

typedef struct node_struct
{
    int data;
    struct node_struct* left;
    struct node_struct* right;
} node;

typedef struct binary_tree_struct
{
  int size;
  node* root;
} binary_tree;

   
void initialize(binary_tree* bt);
bool search(binary_tree* bt, int key);
void insert(binary_tree* bt, int item);
void printinorder(binary_tree* bt);
void printpreorder(binary_tree* bt);
void printpostorder(binary_tree* bt);
int btsize(binary_tree* bt);
int treeheight(binary_tree* bt);

#endif