#include "_internal.h"

int is_empty_impl(const list_t* const self)
{
    return 0;
}

int size_impl(const list_t* const self)
{
    return 0;
}

list_node_t* find_impl(const list_t* const self, int (*compare)(list_node_t*, void*), void* arg)
{
    return NULL;
}

void for_each_impl(const list_t* const self, void (*print_func)(list_node_t*))
{

}

int clear_impl(list_t* const self, void (*free_func)(list_node_t*))
{
    return 0;
}