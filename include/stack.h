/**
 * @file stack.h
 * @author Alifoo
 * @date 2025-09-24
 * @brief Public interface for a simple stack (LIFO) data structure
 * implemented with dynamic memory allocation.
 *
 * This header defines the `Stack` struct and the functions needed to create,
 * manage, and destroy a stack of integers. The implementation uses malloc
 * for dynamic allocation, allowing the user to specify the stack capacity at
 * runtime.
 */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// --- Public Constants and Definitions ---

/**
 * @def STACK_EMPTY
 * @brief Sentinel value returned by stack operations when the stack is empty.
 *
 * Defined as `(-2147483647 - 1)`, which is a portable expression for INT_MIN.
 * Used by functions such as stack_pop() and stack_peek() to indicate an
 * underflow condition.
 */
#define STACK_EMPTY (-2147483647 - 1)

/**
 * @brief Representation of a stack of integers.
 *
 * The `Stack` struct encapsulates an array of integers allocated on the heap,
 * an index for the top element, and the maximum capacity.
 */
typedef struct {
  int *data;    ///< Pointer to the dynamically allocated array of integers
  int top;      ///< Index of the current top element (-1 if empty)
  int capacity; ///< Maximum number of elements the stack can hold
} Stack;

// --- Public Function Prototypes ---

/**
 * @brief Allocate and initialize a new stack.
 *
 * @param capacity Maximum number of elements the stack can hold.
 * @return Pointer to a new `Stack` instance, or NULL if allocation fails.
 *
 * This function must be called before using the stack. The returned pointer
 * should later be freed with stack_destroy().
 */
Stack *stack_create(int capacity);

/**
 * @brief Destroy a stack and release its allocated memory.
 *
 * @param s Pointer to the stack to be destroyed. Safe to pass NULL.
 *
 * This function should be called when the stack is no longer needed.
 */
void stack_destroy(Stack *s);

/**
 * @brief Push a value onto the top of the stack.
 *
 * @param s Pointer to the stack.
 * @param value Value to push.
 * @return `true` if the value was successfully pushed, `false` if the stack is
 * full.
 */
bool stack_push(Stack *s, int value);

/**
 * @brief Pop the value at the top of the stack.
 *
 * @param s Pointer to the stack.
 * @return The popped value, or STACK_EMPTY if the stack is empty.
 */
int stack_pop(Stack *s);

/**
 * @brief Return the value at the top of the stack without removing it.
 *
 * @param s Pointer to the stack.
 * @return The top value, or STACK_EMPTY if the stack is empty.
 */
int stack_peek(const Stack *s);

/**
 * @brief Get the current number of elements in the stack.
 *
 * @param s Pointer to the stack.
 * @return The number of elements currently stored in the stack.
 */
int stack_size(const Stack *s);

/**
 * @brief Check whether the stack is empty.
 *
 * @param s Pointer to the stack.
 * @return `true` if the stack contains no elements, `false` otherwise.
 */
bool stack_is_empty(const Stack *s);

#endif // STACK_H
