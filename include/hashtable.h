#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

// --- Public Constants and Definitions ---

#define MAX_NAME 256
#define TABLE_SIZE 10

// The main data structure used in the hash table
typedef struct {
  char name[MAX_NAME];
  int age;
} person;

// --- Public Function Prototypes ---

/**
 * @brief Initializes the hash table, setting all entries to NULL.
 */
void init_hash_table();

/**
 * @brief Prints the current state of the hash table to the console.
 */
void print_table();

/**
 * @brief Inserts a new person into the hash table.
 * @param p A pointer to the person to insert.
 * @return true if the insertion was successful, false otherwise.
 */
bool hash_table_insert(person *p);

/**
 * @brief Looks up a person in the hash table by name.
 * @param name The name of the person to find.
 * @return A pointer to the person if found, otherwise NULL.
 */
person *hash_table_lookup(char *name);

/**
 * @brief Deletes a person from the hash table by name.
 * @param name The name of the person to delete.
 * @return A pointer to the deleted person if found, otherwise NULL.
 */
person *hash_table_delete(char *name);

#endif
