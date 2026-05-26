#include "_internal.h"

int is_empty_impl(const struct list* const self)
{
    return 0;
}

int size_impl(const struct list* const self)
{
    return 0;
}

struct node* find_impl(const struct list* const self, int (*compare)(struct node*, void*), void* arg)
{
    return NULL;
}

void for_each_impl(const struct list* const self, void (*print_func)(struct node*))
{

}

int clear_impl(struct list* const self, void (*free_func)(struct node*))
{
    return 0;
}