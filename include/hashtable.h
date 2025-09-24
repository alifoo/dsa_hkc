/**
 * @file hashtable.h
 * @author Alifoo and Friends
 * @date 2025-09-03
 * @brief This file contains the public interface for a simple hash table.
 *
 * It is designed to store and manage 'person' structs, providing functions
 * for insertion, lookup, and deletion.
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

// --- Public Constants and Definitions ---

#define MAX_NAME 256  ///< The maximum number of characters for a person's name.
#define TABLE_SIZE 10 ///< The total number of buckets in the hash table.

/**
 * @brief The main data structure used as a value in the hash table.
 *
 * This struct holds information about a single person.
 */
typedef struct {
  char name[MAX_NAME]; ///< The person's full name, used as the key.
  int age;             ///< The person's age.
} person;

// --- Public Function Prototypes ---

/**
 * @brief Initializes the hash table, setting all entries to NULL.
 *
 * This function must be called before any other hash table operations.
 */
void init_hash_table();

/**
 * @brief Prints the current state of the hash table to the console.
 *
 * Useful for debugging and visualizing the table's contents.
 */
void print_table();

/**
 * @brief Inserts a new person into the hash table using linear probing for
 * collisions.
 * @param[in] p A pointer to the person struct to insert. The struct is not
 * copied.
 * @return true if the insertion was successful, false if the table is full.
 */
bool hash_table_insert(person *p);

/**
 * @brief Looks up a person in the hash table by name.
 * @param[in] name The name of the person to find.
 * @return A pointer to the person if found, otherwise NULL.
 */
person *hash_table_lookup(char *name);

/**
 * @brief Deletes a person from the hash table by name.
 *
 * This function marks the slot as deleted to preserve the probing chain.
 * @param[in] name The name of the person to delete.
 * @return A pointer to the deleted person if found, otherwise NULL.
 */
person *hash_table_delete(char *name);

#endif // HASHTABLE_H
