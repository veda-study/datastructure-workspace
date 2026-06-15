#include <stdio.h>
#include "../include/queue.h"

int init_queue(struct queue* const q)
{
    q-> front = -1;
    q-> rear = -1;
    return 0;
}

int is_empty(const struct queue* const q)
{
    if(q->front == q-> rear) return 1;
    return 0;
}

int is_full(const struct queue* const q)
{
    if(q->rear == MAXSIZE -1 ) return 1;
    return 0;
}

void enqueue(struct queue* const q, const int item)
{
    if(is_full(q) == 1) printf("Queue is full!\n");

    q->data[++(q->rear)] = item;
}

int dequeue(struct queue* const q)
{
    if(is_empty(q) == 1)
    {
        printf("Queue is empty!\n"); 
        return -1;
    }

    return q->data[++(q->front)];
}

void print_queue(const struct queue* const q)
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        if(i > q->front && i <= q->rear)
        {
            printf("%d|", q->data[i]);
        }
        else
        {
            printf(" | ");
        }
    }
    printf("\n");
}