/**
 * @file bst.h
 * @author
 * @date 2025-09-25
 * @brief A simple binary search tree (BST) implementation in C.
 *
 * This header provides the data structures and function prototypes
 * for creating, inserting, searching, and printing a binary search tree.
 */

#ifndef BST_H
#define BST_H

#include <stdbool.h>

/**
 * @brief A node in the binary search tree.
 *
 * Each node stores an integer value and pointers
 * to its left and right children.
 */
typedef struct treenode {
    int value;              ///< Value stored in this node
    struct treenode *left;  ///< Pointer to left child
    struct treenode *right; ///< Pointer to right child
} treenode;

/**
 * @brief Creates a new tree node.
 *
 * @param value The integer value to store in the node.
 * @return Pointer to the newly allocated node, or NULL on allocation failure.
 */
treenode *createnode(int value);

/**
 * @brief Prints the tree in a structured format.
 *
 * This function is mainly for debugging and visualization.
 *
 * @param root Pointer to the root node of the tree.
 */
void printtree(treenode *root);

/**
 * @brief Inserts a number into the binary search tree.
 *
 * @param rootptr Pointer to the root pointer of the tree.
 * @param value The value to insert.
 * @return true if the insertion was successful, false if the value already
 * exists.
 */
bool tree_insertnumber(treenode **rootptr, int value);

/**
 * @brief Searches for a value in the binary search tree.
 *
 * @param root Pointer to the root of the tree.
 * @param value The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool tree_findnumber(treenode *root, int value);

#endif // BST_H
