/**
 * @file queue.h
 * @author Alifoo
 * @date 2025-09-25
 * @brief A simple linked-list-based queue implementation in C.
 *
 * This header defines the queue structure and its operations such as
 * initialization, enqueue, dequeue, and printing. The queue stores integers.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/**
 * @brief Return code for dequeue when the queue is empty.
 */
#define QUEUE_EMPTY (-1)

/**
 * @brief Node structure for the queue.
 *
 * Each node stores an integer value and a pointer to the next node.
 */
typedef struct node {
    int value;         ///< The integer value stored in the node
    struct node *next; ///< Pointer to the next node in the queue
} node_t;

/**
 * @brief Queue structure.
 *
 * A queue implemented using a linked list, with pointers to the head and tail.
 */
typedef struct {
    node_t *head; ///< Pointer to the first node in the queue
    node_t *tail; ///< Pointer to the last node in the queue
} queue;

/**
 * @brief Initialize a queue.
 *
 * Sets the head and tail pointers of the queue to NULL.
 *
 * @param[in,out] q Pointer to the queue to initialize.
 */
void init_queue(queue *q);

/**
 * @brief Insert a new value at the end of the queue.
 *
 * @param[in,out] q Pointer to the queue.
 * @param[in] value The integer value to enqueue.
 * @return true if the value was enqueued successfully, false on memory
 * allocation failure.
 */
bool enqueue(queue *q, int value);

/**
 * @brief Remove and return the value at the front of the queue.
 *
 * @param[in,out] q Pointer to the queue.
 * @return The dequeued value, or QUEUE_EMPTY if the queue is empty.
 */
int dequeue(queue *q);

/**
 * @brief Print the contents of the queue to stdout.
 *
 * Each value is printed on a separate line with the format: "t = <value>".
 *
 * @param[in] q Pointer to the queue.
 */
void printqueue(queue *q);

#endif // QUEUE_H
