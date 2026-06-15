#include <stdio.h>
#include "../include/queue.h"

int main(void)
{
    struct queue q;
    init_queue(&q);
 
    enqueue(&q, 1);
    print_queue(&q);
    enqueue(&q, 2);
    print_queue(&q);
    enqueue(&q, 3);
    print_queue(&q);
 
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    
    return 0;
}