#include "../include/list.h"

#include <stdio.h>

int init_list(struct list* const l)
{
    return 0;
}

int destroy_list(struct list* const l)
{
    return 0;
}

int is_empty(const struct list* const l)
{
    return 0;
}

int size(const struct list* const l)
{
    return 0;
}

int find(const struct list* const l, int (*compare)(void*, void*), const void* const arg)
{
    return NULL;
}

int clear(struct list* const l, void (*free_func)(void *))
{
    return 0;
}