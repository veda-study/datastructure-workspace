#pragma once

/**
 * @brief   노드
 */
struct node {
    int data;             /**< 데이터 */  
    struct node *prev;    /**< 노드의 이전 노드 */
    struct node *next;    /**< 노드의 다음 노드 */
};

struct list;

/**
 * @brief   리스트 구조체
 */
struct list {
    struct node* head;  /**< 리스트의 처음 요소 */
    struct node* tail;  /**< 리스트의 마지막 요소 */

    int size;           /**< 요소 개수 */
};

/**
 * @brief       리스트 초기화
 * @param l     대상
 * @return      성공(0), 실패(1)
 */
int init_list(struct list* const l);

/**
 * @brief           리스트 소멸
 * @param l         대상
 * @return          성공(0), 실패(1)
 */
int destroy_list(struct list* const l);

/**
 * @brief       리스트가 비어있는지 확인
 * @param l     대상
 * @return      비어있다면(1)
 */
int is_empty(const struct list* const l);

/**
 * @brief       리스트의 요소 개수 확인
 * @param l     대상
 * @return      요소 개수
 */
int size(const struct list* const l);

/**
 * @brief           리스트의 요소 찾기
 * @param l         대상
 * @param arg       값
 * @return          찾으면(index), 못 찾으면(-1)
 */
int find(const struct list* const l, const int arg);

/**
 * @brief               리스트 출력
 * @param l             대상
 */
void for_each(const struct list* const l);

/**
 * @brief       리스트에 요소 추가
 * @param l     대상
 * @param index 추가할 인덱스
 * @param data  데이터
 * @return      성공(0), 실패(1)
 */
int insert(struct list* const l, const int index, const int data);

/**
 * @brief       리스트의 시작에 요소 추가
 * @param l     대상
 * @param data  데이터
 * @return      성공(0), 실패(1)
 */
int insert_first(struct list* const l, const int data);

/**
 * @brief       리스트의 끝에 요소 추가
 * @param l     대상
 * @param data  데이터
 * @return      성공(0), 실패(1)
 */
int insert_last(struct list* const l, const int data);

/**
 * @brief       리스트의 요소 삭제
 * @param l     대상
 * @param index 삭제할 인덱스
 * @return      요소의 값
 */
int remove_at(struct list* const l, const int index);

/**
 * @brief       리스트의 시작 요소 삭제
 * @param l     대상
 * @return      요소의 값
 */
int remove_first(struct list* const l);

/**
 * @brief       리스트의 끝 요소 삭제
 * @param l     대상
 * @return      요소의 값
 */
int remove_last(struct list* const l);

/**
 * @brief       리스트의 요소 이동
 * @param l     대상
 * @param from  현재 인덱스
 * @param to    목표 인덱스
 * @return      성공(0), 실패(1)
 */
int move(struct list* const l, const int from, const int to);

/**
 * @brief       요소를 리스트의 시작으로 이동
 * @param l     대상
 * @param from  현재 인덱스
 * @return      성공(0), 실패(1)
 */
int move_first(struct list* const l, const int from);

/**
 * @brief       요소를 리스트의 끝으로 이동
 * @param l     대상
 * @param from  현재 인덱스
 * @return      성공(0), 실패(1)
 */
int move_last(struct list* const l, const int from);

/**
 * @brief           리스트 비움
 * @param l         대상
 * @return          성공(0), 실패(1)
 */
int clear(struct list* const l);
