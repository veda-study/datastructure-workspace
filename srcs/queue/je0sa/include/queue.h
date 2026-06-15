#pragma once
#define MAXSIZE 5

/**
 * @brief   큐 구조체
 */
struct queue {
    int front;  /**< 큐의 맨 앞 요소의 위치  */
    int rear;  /**< 큐의 맨 끝 요소의 위치  */
    int data [MAXSIZE];  /**< 데이터를 저장할 큐 공간  */
};

/**
 * @brief       큐 초기화
 * @param s     초기화 대상
 * @return      성공(0), 실패(1)
 */
int init_queue(struct queue* const q);

/**
 * @brief       큐이 비어있는지 확인
 * @param s     대상
 * @return      성공(0), 실패(1)
 */
int is_empty(const struct queue* const q);

/**
 * @brief       큐이 가득 차있는지 확인
 * @param s     대상
 * @return      성공(0), 실패(1)
 */
int is_full(const struct queue* const q);

/**
 * @brief       큐의 top에 data를 추가
 * @param s     대상
 * @param item  추가할 데이터
 * @return      성공(0), 실패(1)
 */
void enqueue(struct queue* const q, const int item);

/**
 * @brief       큐의 top에서 data를 제거하고 반환
 * @param s     대상
 * @return      성공(0), 실패(1)
 */
int dequeue(struct queue* const q);

/**
 * @brief       큐 출력
 * @param s     대상
 * @return      성공(0), 실패(1)
 */
void print_queue(const struct queue* const q);