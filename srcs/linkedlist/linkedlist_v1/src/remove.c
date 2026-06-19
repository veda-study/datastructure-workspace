#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>

int remove_at(struct list* const l, const int index)
{
    /*예외처리, l = 삭제할 노드, index = 삭제할 노드 index*/
    if(!l || index < 0 || index >= l->size) return 1;
    
    /*예외처리*/
    if (index == 0) return remove_first(l);
    if (index == l->size-1) return remove_last(l);

    struct node* removed = l->head;
    
    for(int i=0; i < index; i++){
        removed = removed->next;  
    }

    removed->prev->next = removed->next; //(removed->prev)->next: 삭제할 노드의 왼쪽 노드-> 다음 노드
    removed->next->prev = removed->prev; //(removed->next)->prev: 삭제할 노드의 오른쪽 노드-> 이전노드
    
    int data = removed->data; 
    free(removed);
    l->size--;

    return data;
}

int remove_first(struct list* const l)
{
    if(!l || l->size == 0) return 1;
    
    struct node* removed = l->head;
    int data = removed->data;

    l->head = removed->next;    /*헤드 변경*/

    if (l->head != NULL) {  /*새로운 head가 NULL인지 아닌지 체크*/
        l->head->prev = NULL; /*새로운 head의 prev 포인터를 NULL로 초기화*/
    } else {
        l->tail = NULL; 
    }

    free(removed);
    l->size--;
    
    return data;
}

int remove_last(struct list* const l)
{
    if(!l || l->size == 0) return 1;
    
    struct node* removed = l->tail;
    int data = removed->data;
    
    l->tail = removed->prev;    /*테일 변경*/

    if (l->tail != NULL) {  /*새로운 tail이 NULL인지 아닌지 체크*/
        l->tail->next = NULL; /*새로운 tail의 next 포인터를 NULL로 초기화*/
    } else {
        l->head = NULL; 
    }

    free(removed);
    l->size--;
    
    return data;
}