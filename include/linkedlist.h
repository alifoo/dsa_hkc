/**
 * @file linkedlist.h
 * @author Alifoo
 * @date 2025-09-25
 * @brief A simple singly linked list implementation in C.
 *
 * This file provides the public interface for a linked list of integers.
 * The list supports insertion, search, printing, memory management,
 * and basic node operations.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>

/**
 * @brief A node in the singly linked list.
 *
 * Each node stores an integer value and a pointer to the next node.
 */
typedef struct node {
    int value;         ///< The integer value stored in the node
    struct node *next; ///< Pointer to the next node in the list
} node_t;

/**
 * @brief Prints all the values in the linked list.
 *
 * Iterates from the head of the list to the end, printing each value.
 *
 * @param[in] head Pointer to the head node of the list.
 */
void printlist(node_t *head);

/**
 * @brief Creates a new node with a given integer value.
 *
 * Allocates memory for a new node, sets its value, and initializes its
 * next pointer to NULL.
 *
 * @param[in] value The integer value to store in the new node.
 * @return Pointer to the newly created node.
 */
node_t *create_new_node(int value);

/**
 * @brief Inserts a node at the head of the list.
 *
 * Updates the head pointer to point to the new node.
 *
 * @param[in,out] head Pointer to the head pointer of the list.
 * @param[in] node_to_insert Pointer to the node to insert.
 * @return Pointer to the inserted node.
 */
node_t *insert_at_head(node_t **head, node_t *node_to_insert);

/**
 * @brief Finds the first node with a given value.
 *
 * Traverses the list to search for a node containing the specified value.
 *
 * @param[in] head Pointer to the head node of the list.
 * @param[in] value The integer value to search for.
 * @return Pointer to the node if found, otherwise NULL.
 */
node_t *find_node(node_t *head, int value);

/**
 * @brief Inserts a new node after a given node.
 *
 * Updates pointers so that the new node follows the specified node.
 *
 * @param[in] node_to_insert_after Pointer to the node after which to insert.
 * @param[in] newnode Pointer to the new node to insert.
 */
void insert_after_node(node_t *node_to_insert_after, node_t *newnode);

/**
 * @brief Frees all nodes in the linked list.
 *
 * Iterates through the list, freeing each node’s allocated memory.
 * After calling this function, the list is no longer valid.
 *
 * @param[in] head Pointer to the head node of the list.
 */
void free_list(node_t *head);

#endif // LINKEDLIST_H
