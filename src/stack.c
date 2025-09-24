#include "stack.h"
#include <stdlib.h>

Stack *stack_create(int capacity) {
    Stack *s = malloc(sizeof(Stack));
    if (!s)
        return NULL;

    s->data = malloc(sizeof(int) * capacity);
    if (!s->data) {
        free(s);
        return NULL;
    }

    s->top = -1;
    s->capacity = capacity;
    return s;
}

void stack_destroy(Stack *s) {
    if (s) {
        free(s->data);
        free(s);
    }
}

bool stack_push(Stack *s, int value) {
    if (s->top >= s->capacity - 1)
        return false;

    s->data[++s->top] = value;
    return true;
}

int stack_pop(Stack *s) {
    if (s->top == -1)
        return STACK_EMPTY;
    return s->data[s->top--];
}

int stack_peek(const Stack *s) {
    if (s->top == -1)
        return STACK_EMPTY;
    return s->data[s->top];
}

int stack_size(const Stack *s) { return s->top + 1; }

bool stack_is_empty(const Stack *s) { return s->top == -1; }
