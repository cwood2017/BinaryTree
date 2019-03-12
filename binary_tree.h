#ifndef binaryT_H
#define binaryT_H

typedef struct binary_tree_struct
{
  int size;
  node* root;
} binary_ tree;

typedef struct node_struct
{
  int data;
  struct node_struct* left;
  struct node_struct* right;
} node;
   
   
void initialize(binary_tree* bt);
bool search(binary_tree* bt, int key);
void insert(binary_tree* bt, int item);
void printinorder(binary_tree* bt);
void printpreorder(binary_tree* bt);
void printpostorder(binary_tree* bt);
int btsize(binary_tree* bt);
int treeheight(binary_tree* bt);

#endif