#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 255

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

const char *person_get_key(const void *p) { return ((const person *)p)->name; }

int main() {
    hashtable ht;
    init_hash_table(&ht, 10, person_get_key);

    person *alisson = malloc(sizeof(person));
    strcpy(alisson->name, "Alisson");
    alisson->age = 25;

    hash_table_insert(&ht, alisson);

    person *found = hash_table_lookup(&ht, "Alisson");
    if (found)
        printf("Found %s (%d)\n", found->name, found->age);

    print_table(&ht);

    hash_table_delete(&ht, "Alisson");
    print_table(&ht);
    free(alisson);
    free_hash_table(&ht);
    return 0;
}
