#include "../include/list.h"

#include<stdio.h>

int move(struct list* const l, const int from, const int to)
{
    struct node* from_node, *to_node;
    
    // from node 찾기
    if(l->size - (from + 1) < from){
        from_node = l->tail;
        int dst = l->size - (from + 1);
        for(int i=0; i<dst; i++){
            from_node = from_node->prev;
        }
    } else{
        from_node = l->head;
        for(int i=0; i<from; i++){
            from_node = from_node->next;
        }
    }
    // to node 찾기
    if(l->size - (to + 1) < to){
        to_node = l->tail;
        int dst = l->size - (to + 1);
        for(int i=0; i<dst; i++){
            to_node = to_node->prev;
        }
    } else{
        to_node = l->head;
        for(int i=0; i<to; i++){
            to_node = to_node->next;
        }
    }
    // 연결 끊기
    from_node->prev->next = from_node->next;
    from_node->next->prev = from_node->prev;

    // 연결 하기(to_node 이전에 insert)
    to_node->prev->next = from_node;
    from_node-> prev = to_node->prev;
    to_node->prev = from_node;
    from_node->next = to_node;

    return 0;
}

int move_first(struct list* const l, const int from)
{
    struct node* from_node;
    
    // from node 찾기
    if(l->size - (from + 1) < from){
        from_node = l->tail;
        int dst = l->size - (from + 1);
        for(int i=0; i<dst; i++){
            from_node = from_node->prev;
        }
    } else{
        from_node = l->head;
        for(int i=0; i<from; i++){
            from_node = from_node->next;
        }
    }

    // 연결 끊기
    from_node->prev->next = from_node->next;
    from_node->next->prev = from_node->prev;

    // head에 insert
    from_node->prev = NULL;
    from_node->next = l->head;
    l->head->prev = from_node;
    l->head = from_node;

    return 0;
}

int move_last(struct list* const l, const int from)
{
    struct node* from_node;
    
    // from node 찾기
    if(l->size - (from + 1) < from){
        from_node = l->tail;
        int dst = l->size - (from + 1);
        for(int i=0; i<dst; i++){
            from_node = from_node->prev;
        }
    } else{
        from_node = l->head;
        for(int i=0; i<from; i++){
            from_node = from_node->next;
        }
    }

    // 연결 끊기
    from_node->prev->next = from_node->next;
    from_node->next->prev = from_node->prev;

    // tail에 insert
    from_node->prev = l->tail;
    from_node->next = NULL;
    l->tail->next = from_node;
    l->tail = from_node;

    return 0;
}