#include "stack.h"
#include <stdio.h>

int main() {
    Stack *s = stack_create(10);
    if (!s) {
        printf("failed to create stack!\n");
        return 1;
    }
    stack_push(s, 57);
    printf("peek() result: %d\n", stack_peek(s));

    stack_push(s, 92);
    printf("peek() result: %d\n", stack_peek(s));

    stack_push(s, 31);
    printf("peek() result: %d\n", stack_peek(s));

    printf("size() result: %d\n", stack_size(s));
    printf("pop() result: %d\n", stack_pop(s));
    printf("size() result: %d\n", stack_size(s));

    stack_destroy(s);
    return 0;
}
