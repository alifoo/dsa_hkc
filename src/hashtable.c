#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 255
#define DELETED_NODE ((void *)0xFFFFFFFFFFFFFFFUL)

typedef struct {
    void **table;
    size_t size;
    const char *(*get_key)(const void *);
} hashtable;

void init_hash_table(hashtable *ht, const char *(*get_key)(const void *),
                     size_t size) {
    ht->table = malloc(size * sizeof(void *));
    for (size_t i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    ht->size = size;
    ht->get_key = get_key;
}

void free_hash_table(hashtable *ht) {
    free(ht->table);
    ht->table = NULL;
    ht->size = 0;
}

unsigned int hash(const char *key, size_t size) {
    unsigned int hash_value = 0;
    for (size_t i = 0; key[i] != '\0'; i++) {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % size;
    }
    return hash_value;
}

void print_table(const hashtable *ht) {
    printf("Hash table:\n");
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] == NULL)
            printf("%d: ---\n", i);
        else if (ht->table[i] == DELETED_NODE)
            printf("%d: <deleted>\n", i);
        else
            printf("%d: %s\n", i, ht->get_key(ht->table[i]));
    }
}

bool hash_table_insert(hashtable *ht, void *value) {
    if (!value)
        return false;
    const char *key = ht->get_key(value);
    size_t index = hash(key, ht->size);

    for (size_t i = 0; i < ht->size; i++) {
        size_t try = (index + i) % ht->size;
        if (ht->table[try] == NULL || ht->table[try] == DELETED_NODE) {
            ht->table[try] = value;
            return true;
        }
    }
    return false;
}

void *hash_table_lookup(const hashtable *ht, const char *key) {
    size_t index = hash(key, ht->size);

    for (size_t i = 0; i < ht->size; i++) {
        size_t try = (index + i) % ht->size;

        if (ht->table[try] == NULL) {
            return NULL;
        }
        if (ht->table[try] == DELETED_NODE)
            continue;
        if (strcmp(ht->get_key(ht->table[try]), key) == 0) {
            return ht->table[try];
        }
    }
    return NULL;
}

void *hash_table_delete(hashtable *ht, const char *key) {
    size_t index = hash(key, ht->size);

    for (size_t i = 0; i < ht->size; i++) {
        size_t try = (index + i) % ht->size;

        if (ht->table[try] == NULL)
            return NULL;
        if (ht->table[try] == DELETED_NODE)
            continue;
        if (strcmp(ht->get_key(ht->table[try]), key) == 0) {
            void *tmp = ht->table[try];
            ht->table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}
