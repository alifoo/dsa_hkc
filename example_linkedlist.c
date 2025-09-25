#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
    }

    tmp = find_node(head, 13);
    printf("found node with value %d\n", tmp->value);

    printlist(head);
    insert_after_node(tmp, create_new_node(75));

    printlist(head);

    free_list(head);

    return 0;
}
