/* Project 7: Binary Search Tree
Nick Crepeau 
Cody Wood 
Ethan Rocheleau 
Nate Johnson
*/

#include <stdio.h>
#include "binary_tree.h"
#include <string.h> /*for strlen if needed later */
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    FILE *inFile = NULL; // File pointer
    binary_tree* bt;
    bt=malloc(sizeof(struct binary_tree_struct));
    initialize(bt);
    char fileName[50];
    /* assumes no more than 1000 numbers in input file */
    int nodeList[1000];
    /* readNode used to read nodes in from file */
    int readNode;
    /* endOfFile used for reading in node list. Can't be zero to start */
    int endOfFile=1;
    /* int cursor for iterating- may not need in final draft */
    int cursor = 0;
    int i;

    /* error check for correct number of arguments (should be 2) */
    if (argc != 2) {
        printf("The number of command line arguments is wrong.\n");
        exit(1);
    }
/* Get filename from argument and open it*/
    strcpy(fileName, argv[1]);
    inFile = fopen(fileName, "r");
/* error if can't open file */
    if (inFile == NULL) {
        printf("Could not open file.\n");
        exit(1); // -1 indicates error
    }
/* load numbers into nodeList array */
/* note: we can load directly into our binary tree  */
    while (!feof(inFile)) {
        if (endOfFile != 0) {
            fscanf(inFile, "%d", &readNode);
            nodeList[cursor]=readNode;
            cursor++;
        }
    }
    /*move from array into tree*/
    for (i=0; i<cursor; i++) {
        insert(bt,nodeList[i]);
    }
    /*for debugging*/
    /*printf("number of nodes:  %d", cursor);*/
    /* test methods assigned */
    printf("Print in order\n");
    printinorder(bt);
    printf("\nPrint pre order\n");
    printpreorder(bt);
    printf("\nPrint post order\n");
    printpostorder(bt);
    printf("\n");
    bool found = search(bt, 33);
    if (found) {
        printf("FOUND 33\n");
    }
    found = search(bt, 38);
    if (found) {
        printf("FOUND 38\n");
    }
    printf("Number of elements in tree: %d\n", btsize(bt));
    printf("Tree height: %d\n", treeheight(bt));
}
