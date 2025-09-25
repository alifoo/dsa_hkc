/**
 * @file hashtable.h
 * @author Alifoo
 * @date 2025-09-03
 * @brief A simple, generic hash table implementation using a dynamic struct.
 *
 * This file provides the public interface for a hash table that can store
 * any kind of data. The table size is dynamic and allocated at runtime.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include <stddef.h>

// --- Public Constants and Definitions ---

#define DELETED_NODE                                                           \
    ((void *)0xFFFFFFFFFFFFFFFUL) ///< Special marker for deleted entries

/**
 * @brief Function pointer type for extracting a string key from an object.
 *
 * The function takes a pointer to an object and returns a pointer to a string
 * (the key) associated with that object.
 */
typedef const char *(*get_key_func)(const void *);

/**
 * @brief The hash table structure.
 *
 * Stores a dynamically allocated array of void* pointers, so it can handle
 * any data type. The user must supply a function to extract string keys from
 * the stored data.
 */
typedef struct {
    void **table;         ///< Dynamic array of pointers to stored objects
    size_t size;          ///< Number of buckets in the table
    get_key_func get_key; ///< Function to extract keys from objects
} hashtable;

// --- Public Function Prototypes ---

/**
 * @brief Initializes the hash table with a given size.
 *
 * @param[in,out] ht A pointer to the hashtable instance.
 * @param[in] get_key A function that extracts a string key from stored objects.
 * @param[in] size Number of buckets to allocate for the table.
 */
void init_hash_table(hashtable *ht, get_key_func get_key, size_t size);

/**
 * @brief Frees the dynamically allocated table inside the hash table.
 *
 * Does not free the stored objects themselves; the user must do that
 * separately.
 *
 * @param[in,out] ht A pointer to the hashtable instance.
 */
void free_hash_table(hashtable *ht);

/**
 * @brief Prints the current state of the hash table to the console.
 *
 * Useful for debugging and visualizing the table's contents.
 *
 * @param[in] ht A pointer to the hashtable instance.
 */
void print_table(const hashtable *ht);

/**
 * @brief Inserts an object into the hash table using linear probing.
 *
 * @param[in,out] ht A pointer to the hashtable instance.
 * @param[in] item A pointer to the object to insert. The object is not copied.
 * @return true if the insertion was successful, false if the table is full.
 */
bool hash_table_insert(hashtable *ht, void *item);

/**
 * @brief Looks up an object in the hash table by its string key.
 *
 * @param[in] ht A pointer to the hashtable instance.
 * @param[in] key The key string to search for.
 * @return A pointer to the object if found, otherwise NULL.
 */
void *hash_table_lookup(const hashtable *ht, const char *key);

/**
 * @brief Deletes an object from the hash table by its string key.
 *
 * This function marks the slot as deleted to preserve the probing chain.
 *
 * @param[in,out] ht A pointer to the hashtable instance.
 * @param[in] key The key string of the object to delete.
 * @return A pointer to the deleted object if found, otherwise NULL.
 */
void *hash_table_delete(hashtable *ht, const char *key);

#endif // HASHTABLE_H
