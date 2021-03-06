/* Project 7: Binary Search Tree
Nick Crepeau 
Cody Wood 
Ethan Rocheleau 
Nate Johnson
*/

#include "binary_tree.h"
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>


void initialize(binary_tree* bt) {
    bt->size = 0;
    bt->root = 0;
};

bool search(binary_tree* bt, int key) {
    node* currentNode = bt -> root;

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
    return NULL;
}

void insert(binary_tree* bt, int item) {
    int flag = 0;
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
                    /*  case 6 */
                    cursor = cursor->right;
                }
            }
        }
    }
    /* for debug  */
    /* printf("inserted %d,  flag  %d\n", newNode->data, flag); */
}

/*helper method for printpreorder */
void preOrder(node* curr){
if(curr == NULL){
    return;
}
printf("%d ", curr->data);
preOrder(curr->left);
preOrder(curr->right);

}
/* printpreorder depends on preorder*/
void printpreorder(binary_tree* bt){
    node* curr = bt->root;
    preOrder(curr);


}
/*helper method for printinorder */
void pOrder(node* curr) {
    if(curr == NULL){
        return;
    }
    pOrder(curr->left);
    printf("%d ", curr->data);
    pOrder(curr->right);

}
/* printinorder depends on porder*/
void printinorder(binary_tree* bt){
    node* curr = bt->root;
    pOrder(curr);

    return;

}
/*helper method for printpostorder */
void ptorder(node* curr){
    if(curr == NULL){
        return;
    }
    ptorder(curr->left);
    ptorder(curr->right);
    printf("%d ", curr->data);
}
/* printpostorder depends on ptorder*/
void printpostorder(binary_tree* bt){
    node* curr = bt->root;
    ptorder(curr);

    return;
}

/*helper method for recurse tree */
int max(int a, int b) {
    if (a>b) return a;
    else return b;
}
/*helper method to calculate tree height */
int recurseTree(node* n) {
    int left = 0;
    int right = 0;
    if (n == 0) return 0;
    left = recurseTree(n->left);
    right = recurseTree(n->right);
    return max(left,right)+1;

}
/* tree height depends on recurseTree and max*/
int treeheight(binary_tree* bt) {
    int height;
    height = recurseTree(bt->root);
    return height -1;
}

int btsize(binary_tree* bt) {
    return bt->size;
}


