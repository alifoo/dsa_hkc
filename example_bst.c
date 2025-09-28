#include "bst.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    treenode *root = NULL;

    tree_insertnumber(&root, 15);
    tree_insertnumber(&root, 11);
    tree_insertnumber(&root, 24);
    tree_insertnumber(&root, 5);
    tree_insertnumber(&root, 19);
    tree_insertnumber(&root, 16);

    printtree(root);

    printf("%d (%d)\n", 16, tree_findnumber(root, 16));
    printf("%d (%d)\n", 15, tree_findnumber(root, 15));
    printf("%d (%d)\n", 5, tree_findnumber(root, 5));
    printf("%d (%d)\n", 115, tree_findnumber(root, 115));
    printf("%d (%d)\n", 1, tree_findnumber(root, 1));
    printf("%d (%d)\n", 7, tree_findnumber(root, 7));
}
