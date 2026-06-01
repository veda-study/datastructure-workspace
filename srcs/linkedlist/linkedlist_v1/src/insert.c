#include "../include/list.h"
#include <stdlib.h>
#include <stdio.h>

int insert(struct list* const l, const int index, const int data)
{
    if (!l) return 1;
    else if (index<0 || index > l->size) return 1;
    else if (index == 0) return insert_first(l, data);
    else if (index == l->size) return insert_last(l, data);

    struct node* new_node = malloc(sizeof(struct node));    //new_node 생성
    if (!new_node) return 1;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    struct node* prev_node = l->head;
    for (int i = 0; i < index - 1; i++) {                     // index 바로 앞에까지
        prev_node = prev_node->next;
    }
    struct node* next_node = prev_node->next;

    new_node->prev = prev_node;
    new_node->next = next_node;

    prev_node->next = new_node;
    next_node->prev = new_node;

    l->size++;

    return 0;
}

int insert_first(struct list* const l, const int data)
{
    if (!l) return 1;

    struct node* new_node = malloc(sizeof(struct node));    // new_node 생성
    if (!new_node) return 1;

    new_node->data = data;                                  // new_node의 값 저장
    new_node->prev = NULL;                                  // 이전 노드
    new_node->next = NULL;                                  // 다음 노드

    if (l->size == 0) {                                     // 리스트 값이 없을 때
        l->head = new_node;                                 // new_node의 헤드
        l->tail = new_node;                                 // new_node의 꼬리
    }
    else {                                                  // 리스트에 값이 있으면
        new_node->next = l->head;                           // new_node가 현재 노드의 헤드를 표시
        l->head->prev = new_node;                           // 현재 노드의 이전이 new_node임을 표시
        l->head = new_node;                                 // 현재 노드를 new_node로 변경
    }
    l->size++;

    return 0;
}

int insert_last(struct list* const l, const int data)
{
    if (!l) return 1;

    struct node* new_node = malloc(sizeof(struct node));
    if (!new_node) return 1;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (l->size == 0) {
        l->head = new_node;
        l->tail = new_node;
    }
    else {                                              // 리스트가 비어있지 않을 때
        new_node->prev = l->tail;                       // new_node의 이전이 현재 노드의 꼬리
        l->tail->next = new_node;                       // 이전 노드의 꼬리의 다음이 new_node 
        l->tail = new_node;                             // 현재 노드를 new_node로 변경
    }
    l->size++;

    return 0;
}