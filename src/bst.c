#include "bst.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

treenode *createnode(int value) {
    treenode *result = malloc(sizeof(treenode));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printtabs(int numtabs) {
    for (int i = 0; i < numtabs; i++) {
        printf("\t");
    }
}

void printtree_rec(treenode *root, int level) {
    if (root == NULL) {
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    printtabs(level);

    printf("value = %d\n", root->value);
    printtabs(level);

    printf("left\n");
    printtree_rec(root->left, level + 1);

    printtabs(level);
    printf("right\n");

    printtree_rec(root->right, level + 1);
    printtabs(level);

    printf("\n");
}

void printtree(treenode *root) { printtree_rec(root, 0); }

bool tree_insertnumber(treenode **rootptr, int value) {
    treenode *root = *rootptr;
    if (root == NULL) {
        (*rootptr) = createnode(value);
        return true;
    }
    if (value == root->value) {
        return false;
    }
    if (value < root->value) {
        return tree_insertnumber(&(root->left), value);
    } else {
        return tree_insertnumber(&(root->right), value);
    }
}

bool tree_findnumber(treenode *root, int value) {
    if (root == NULL)
        return false;
    if (root->value == value) {
        return true;
    }
    if (value < root->value) {
        return tree_findnumber(root->left, value);
    } else {
        return tree_findnumber(root->right, value);
    }
}
