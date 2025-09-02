#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFFUL)

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {
    printf("Start\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(person *p) {
    if (p == NULL)
        return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) {
            return false;
        }
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strncmp(hash_table[try]->name, name, MAX_NAME) == 0) {
            return hash_table[try];
        }
    }
    return NULL;
}

person *hash_table_delete(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return NULL;
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strncmp(hash_table[try]->name, name, MAX_NAME) == 0) {
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

int example() {
    init_hash_table();
    print_table();

    person alisson = {.name = "Alisson", .age = 256};
    person marcos = {.name = "Marcos", .age = 18};
    person rafa = {.name = "Rafa", .age = 20};

    hash_table_insert(&alisson);
    hash_table_insert(&marcos);
    hash_table_insert(&rafa);
    print_table();

    person *tmp = hash_table_lookup("Marcos");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }
    print_table();
    hash_table_delete("Alisson");
    tmp = hash_table_lookup("Alisson");
    if (tmp == NULL) {
        printf("Not found!\n");
    } else {
        printf("Found %s.\n", tmp->name);
    }
    print_table();

    /*printf("Jacob => %u\n", hash("Jacob"));
    printf("Alisson => %u\n", hash("Alisson"));*/

    return 0;
}
