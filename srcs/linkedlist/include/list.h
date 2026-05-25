#pragma once

#include <stddef.h>

/**
 * @brief   노드로 구조체 시작 주소 반환 함수
 */
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

/**
 * @brief   구조체 임베딩 노드
 */
typedef struct _list_node {
    struct _list_node *prev;    /**< 노드의 이전 노드 */
    struct _list_node *next;    /**< 노드의 다음 노드 */
} list_node_t;

// 전방 선언 -> _list_ops에서 사용하기 때문
typedef struct _list list_t;

/**
 * @brief   함수 포인터 테이블
 */
typedef struct _list_ops {
    int (*is_empty)(const list_t* const self);
    int (*size)(const list_t* const self);
    list_node_t* (*find)(const list_t* const self, int (*compare)(list_node_t*, void*), void* arg);
    void (*for_each)(const list_t* const self, void (*print_func)(list_node_t*));

    int (*insert)(list_t* const self, const int index, list_node_t* const node);
    int (*insert_first)(list_t* const self, list_node_t* const node);
    int (*insert_last)(list_t* const self, list_node_t* const node);

    list_node_t* (*remove)(list_t* const self, const int index);
    list_node_t* (*remove_first)(list_t* const self);
    list_node_t* (*remove_last)(list_t* const self);

    int (*move)(list_t* const self, const int index, list_node_t* const node);
    int (*move_first)(list_t* const self, list_node_t* const node);
    int (*move_last)(list_t* const self, list_node_t* const node);

    int (*clear)(list_t* const self, void (*free_func)(list_node_t*));
} list_ops_t;

/**
 * @brief   리스트 관리 구조체
 * @details pimpl 구조 사용하여 컴파일 의존성 낮춤
 */
struct _list {
    struct _list_internal *pimpl;   /**< pimpl 포인터 */
    const list_ops_t *ops;          /**< 함수 포인터 연결 */
};

/**
 * @brief       리스트 초기화
 * @param list  대상
 * @return      성공(0), 실패(1)
 */
int init_list(list_t* const list);

/**
 * @brief           리스트 소멸
 * @param list      대상
 * @param free_func 노드 초기화 함수
 * @return          성공(0), 실패(1)
 */
int destroy_list(list_t* const list, void (*free_func)(list_node_t*));