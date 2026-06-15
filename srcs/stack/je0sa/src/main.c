#include <stdio.h>
#include "../include/stack.h"

int main(void)
{   
    struct stack myStack;
    
    if (init_stack(&myStack) != 0) {
        fprintf(stderr, "[ERROR] Stack init fail!\n");
        return 1;
    }
    
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);
    
    printf("peek: %d \n", peek(&myStack));

    printf("pop: %d \n", pop(&myStack));
    printf("pop: %d \n", pop(&myStack));

    printf("peek: %d \n", peek(&myStack));
    
    printf("pop: %d \n", pop(&myStack));

    printf("peek: %d \n", peek(&myStack));
    return 0;
}