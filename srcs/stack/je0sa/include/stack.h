#pragma once
#define MAXSIZE 100

/**
 * @brief   스택 구조체 -> 여러개의 스택 생성을 위함
 */
struct stack {
    int top;  /**< 스택의 가장 위 요소의 위치  */
    int data [MAXSIZE];  /**< 데이터를 저장할 스택 공간  */
};

/**
 * @brief       스택 초기화
 * @param s     초기화 대상
 * @return      성공(0), 실패(1)
 */
int init_stack(struct stack* const s);

/**
 * @brief       스택이 비어있는지 확인
 * @param s     대상
 * @return      성공(0), 실패(1)
 */
int is_empty(const struct stack* const s);

/**
 * @brief       스택이 가득 차있는지 확인
 * @param s     대상
 * @return      성공(0), 실패(1)
 */
int is_full(const struct stack* const s);

/**
 * @brief       스택의 top에 data를 추가
 * @param s     대상
 * @param item  추가할 데이터
 * @return      성공(0), 실패(1)
 */
void push(struct stack* const s, const int item);

/**
 * @brief       스택의 top에서 data를 제거하고 반환
 * @param s     대상
 * @return      성공(0), 실패(1)
 */
int pop(struct stack* const s);

/**
 * @brief       스택의 top에서 data를 제거하지 않고 반환
 * @param s     대상
 * @return      성공(0), 실패(1)
 */
int peek(const struct stack* const s);