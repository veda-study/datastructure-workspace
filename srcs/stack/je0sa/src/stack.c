#include <stdio.h>
#include "../include/stack.h"

int init_stack(struct stack* const s)
{
    s->top = -1;
    return 0;
}

int is_empty(const struct stack* const s)
{
    if(s->top == -1) return 1;

    return 0;
}

int is_full(const struct stack* const s)
{
    if(s->top >= MAXSIZE - 1) return 1;

    return 0;
}

void push(struct stack* const s, const int item)
{
    if(is_full(s) == 1) printf("Stack is full!\n");

    s->data[++(s->top)] = item;
}

int pop(struct stack* const s)
{
    if(is_empty(s) == 1) printf("Stack is empty!\n");

    return s->data[(s->top)--];
}

int peek(const struct stack* const s)
{
    if(is_empty(s) == 1) printf("Stack is empty!\n");
    return s->data[s->top];
}
