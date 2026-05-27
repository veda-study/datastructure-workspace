#include "../include/list.h"

#include <stdio.h>

int init_list(struct list* const l)
{
    if (!l) return 1;

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return 0;
}

int destroy_list(struct list* const l)
{
    if (!l) return 1;

    clear(l);

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return 0;
}

int is_empty(const struct list* const l)
{
    if (!l) return 1;

    return l->size == 0;
}

int size(const struct list* const l)
{
    if (!l) return 0;

    return l->size;
}

int find(const struct list* const l, const int arg)
{
    if (!l) return -1;

    int i = 0;
    struct node* curr = l->head;

    while(curr != NULL) {
        if (curr->data == arg) {
            return i;
            break;
        }
        i++; curr = curr->next;
    }

    return -1;
}

void for_each(const struct list* const l)
{
    if (!l) return;
    
    struct node* curr = l->head;

    printf("List: [");
    while (curr != NULL) {
        printf("%d ", curr->data);
    }
    printf("]\n");
}

int clear(struct list* const l)
{
    if (!l) return 1;

    while (!is_empty(l)) {
        remove_first(l);
    }

    return 0;
}
