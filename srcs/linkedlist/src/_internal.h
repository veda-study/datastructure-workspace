#pragma once

#include "../include/list.h"

/**
 * @brief   실제 리스트 구조체
 * @details 파수꾼 노드 채용하여 NULL 안전
 */
typedef struct _list_internal {
    list_node_t head;   /**< 리스트의 시작(파수꾼 노드) */
    list_node_t tail;   /**< 리스트의 끝(파수꾼 노드) */
    int size;           /**< 리스트의 요소 개수 */
} list_internal_t;

/**
 * @brief       리스트가 비어있는지 확인
 * @param self  대상
 * @return      비어있다면(1)
 */
int is_empty_impl(const list_t* const self);

/**
 * @brief       리스트의 요소 개수 확인
 * @param self  대상
 * @return      요소 개수
 */
int size_impl(const list_t* const self);

/**
 * @brief           리스트의 요소 찾기
 * @param self      대상
 * @param compare   비교 사용자 정의 함수
 * @param arg       값
 * @return          찾으면(node), 못 찾으면(NULL)
 */
list_node_t* find_impl(const list_t* const self, int (*compare)(list_node_t*, void*), void* arg);

/**
 * @brief               리스트 출력
 * @param self          대상
 * @param print_func    출력 사용자 정의 함수
 */
void for_each_impl(const list_t* const self, void (*print_func)(list_node_t*));

/**
 * @brief       리스트에 요소 추가
 * @param self  대상
 * @param index 추가할 인덱스
 * @param node  요소
 * @return      성공(0), 실패(1)
 */
int insert_impl(list_t* const self, const int index, list_node_t* const node);

/**
 * @brief       리스트의 시작에 요소 추가
 * @param self  대상
 * @param node  요소
 * @return      성공(0), 실패(1)
 */
int insert_first_impl(list_t* const self, list_node_t* const node);

/**
 * @brief       리스트의 끝에 요소 추가
 * @param self  대상
 * @param node  요소
 * @return      성공(0), 실패(1)
 */
int insert_last_impl(list_t* const self, list_node_t* const node);

/**
 * @brief       리스트의 요소 삭제
 * @param self  대상
 * @param index 삭제할 인덱스
 * @return      성공(요소), 실패(NULL)
 */
list_node_t* remove_impl(list_t* const self, const int index);

/**
 * @brief       리스트의 시작 요소 삭제
 * @param self  대상
 * @return      성공(요소), 실패(NULL)
 */
list_node_t* remove_first_impl(list_t* const self);

/**
 * @brief       리스트의 끝 요소 삭제
 * @param self  대상
 * @return      성공(요소), 실패(NULL)
 */
list_node_t* remove_last_impl(list_t* const self);

/**
 * @brief       리스트의 요소 이동
 * @param self  대상
 * @param index 이동할 인덱스
 * @param node  요소
 * @return      성공(0), 실패(1)
 */
int move_impl(list_t* const self, const int index, list_node_t* const node);

/**
 * @brief       요소를 리스트의 시작으로 이동
 * @param self  대상
 * @param node  요소
 * @return      성공(0), 실패(1)
 */
int move_first_impl(list_t* const self, list_node_t* const node);

/**
 * @brief       요소를 리스트의 끝으로 이동
 * @param self  대상
 * @param node  요소
 * @return      성공(0), 실패(1)
 */
int move_last_impl(list_t* const self, list_node_t* const node);

/**
 * @brief           리스트 비움
 * @param self      대상
 * @param free_func free 사용자 정의 함수
 * @return          성공(0), 실패(1)
 */
int clear_impl(list_t* const self, void (*free_func)(list_node_t*));