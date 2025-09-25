#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    queue q1, q2, q3;
    init_queue(&q1);

    enqueue(&q1, 56);
    enqueue(&q1, 78);
    enqueue(&q1, 23);
    enqueue(&q1, 988);
    enqueue(&q1, 13);

    printqueue(&q1);
    puts("Dequeueing 2 times!");
    dequeue(&q1);
    dequeue(&q1);
    printqueue(&q1);

    return 0;
}
