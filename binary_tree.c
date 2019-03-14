//
// Created by njayj on 3/13/2019.
//

#include "binary_tree.h"
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

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


void initialize(binary_tree* bt) {
    bt->size = 0;
    bt->root = 0;
};

void initialize(binary_tree* bt)
{
    bt->root = NULL;
    bt->size = 0;
}

bool search(binary_tree* bt, int key) {
struct node_struct currentNode = bt->root

while (currentNode != NULL) {
if (key == currentNode->data) {
return currentNode;
}
else if (key< currentNode->data) {
currentNode = currentNode->left;
}
else {
currentNode = currentNode->right;
}
} 
return null;
}

void insert(binary_tree* bt, int item) {
    int flag = 0;
    int last;
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    node *cursor;
    cursor = (node*)malloc(sizeof(node));

    newNode->data = item;
    newNode->left = 0;
    newNode->right = 0;
    /*
     * case 0: empty.  add node to root and end.
     * case 1: less than, left node empty so just add to left and end
     * case 2: less than, > current left node, current left node's
     *      right node is empty, so just add to current left node's
     *      right node
     * case 3: less than, current left node has right node, move cursor
     *     to current left node
     * case 4: greater than, right node empty so just add to rightt and end
     * case 5: greater than, < current right node, current right node's
     *      left node is empty, so just add to current right nodes left node
     * case 6: greater than, current right node has left node, move cursor
     *     to current right node
     */
    /* case 0 */
    if (bt->root == 0) {
        bt->root = newNode;
        bt->size = 1;
    }
    else {
        cursor = bt->root;

        while (flag == 0) {
            if (cursor->data > item) {

                /* case 1 */
                if (cursor->left == 0) {
                    cursor->left = newNode;
                    flag = 1;
                    bt->size++;
                } else {
                    /*case 2 */
                    if (cursor->left->data < item && cursor->left->right == 0) {
                        //newNode->left = cursor->left;
                        cursor->left->right = newNode;
                        flag = 2;
                        bt->size++;
                    }
                        /*case 3 */
                    else {
                        cursor = cursor->left;
                    }

                }
            }

                /*new node is bigger than current position */
            else {
                /*case 4 */
                if (cursor->right == 0) {
                    cursor->right = newNode;
                    flag = 4;
                    bt->size++;
                } else
                    /*case 5 */
                if (cursor->right->data > item && cursor->right->left == 0) {
                    //newNode->right = cursor->right;
                    cursor->right->left = newNode;
                    flag = 5;
                    bt->size++;
                } else {
                    cursor = cursor->right;
                }
            }
        }


    }
    /* for debug  */
    /* printf("inserted %d,  flag  %d\n", newNode->data, flag); */
}


void preOrder(node* curr){
if(curr == NULL){
    return;
}
printf("%d ", curr->data);
preOrder(curr->left);
preOrder(curr->right);

}
void printpreorder(binary_tree* bt){
    node* curr = bt->root;
    preOrder(curr);


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


