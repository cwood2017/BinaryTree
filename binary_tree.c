//
// Created by njayj on 3/13/2019.
//

#include "binary_tree.h"
#include <stdbool.h>

void initialize(binary_tree* bt)
{
    bt->root = NULL;
    bt->size = 0;
}

bool search(binary_tree* bt, int key)
{
}

void insert(binary_tree* bt, int item)
{
}



void printpreorder(binary_tree* bt)
{
}

void pOrder(node* curr) {
    if(curr == NULL){
        return;
    }
    pOrder(curr->left);
    printf("%d ", curr->data);
    pOrder(curr->right);

}
void printinorder(binary_tree* bt){
    node* curr = bt->root;
    pOrder(curr);

    return;

}
void ptorder(node* curr){
    if(curr == NULL){
        return;
    }
    postorder(curr->left);
    postorder(curr->right);
    printf("%d ", curr->data);
}
void printpostorder(binary_tree* bt){
    node* curr = bt->root;
    ptorder(curr);

    return;
}


int max(int a, int b) {
    if (a>b) return a;
    else return b;
}

int recurseTree(node* n) {
    int left = 0;
    int right = 0;
    if (n == 0) return 0;
    left = recurseTree(n->left);
    right = recurseTree(n->right);
    return max(left,right)+1;

}

int treeheight(binary_tree* bt) {
    int height;
    height = recurseTree(bt->root);
    return height -1;
}

int btsize(binary_tree* bt) {
    return bt->size;
}
