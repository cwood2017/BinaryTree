#include <stdio.h>
#include "binary_tree.h"
#include <string.h> /*for strlen if needed later */

int main(int argc, char* argv[]) {
    FILE *inFile = NULL; // File pointer
    /* TODO change to malloc based on strlen of arg[1] */
    char fileName[50];
    /* assumes no more than 1000 numbers in input file */
    int nodeList[1000];
    /* readNode used to read nodes in from file */
    int readNode;
    /*used to clear buffer if needed- not used now */
    char c;
    /* endOfFile used for reading in node list. Can't be zero to start */
    int endOfFile=1;
    /* int cursor for iterating- may not need in final draft */
    int cursor = 0;
    int i;


/* Get filename from argument and open it*/
    strcpy(fileName, argv[1]);
    inFile = fopen(fileName, "r");
/* error if can't open file */
    if (inFile == NULL) {
        printf("Could not open file.\n");
        return -1; // -1 indicates error
    }
/* load nodes into nodeList array */
/* note: we can load directly into our binary tree in the
 * final version.  this is just to play around with */
    while (!feof(inFile)) {
        if (endOfFile != 0) {
            fscanf(inFile, "%d", &readNode);
            nodeList[cursor]=readNode;
            cursor++;
        }
    }
    /*for debugging- delete in final version*/
    for (i=0; i<cursor; i++) {
        printf("%d\n",nodeList[i]);
    }
    /*for debugging- delete in final version*/
    printf("number of nodes:  %d", cursor);


    printf("Print in order\n");
    printinorder(&bt);
    printf("\nPrint pre order\n");
    printpreorder(&bt);
    printf("\nPrint post order\n");
    printpostorder(&bt);
    printf("\n");
    found = search(&bt, 33);
    if (found) {
        printf("FOUND 33\n");
    }
    found = search(&bt, 38);
    if (found) {
        printf("FOUND 38\n");
    }
    printf("Number of elements in tree: %d\n", btsize(&bt));
    printf("Tree height: %d\n", treeheight(&bt));
}
