#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

/* -------------------------------------------------------------------------
 * 1. 헬퍼 함수 세팅
 * ------------------------------------------------------------------------- */
/* [헬퍼] 정수 데이터를 담는 노드 동적 할당 */
struct node* create_node(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (!n) {
        fprintf(stderr, "[ERROR] 메모리 할당 실패\n");
        exit(1);
    }
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    
    return n;
}

/* -------------------------------------------------------------------------
 * 2. 메인 테스트 로직
 * ------------------------------------------------------------------------- */
int main(void)
{
    printf("🚀 VEDA Linked List (v1 - Hardcoded Data) ADT 테스트 시작\n\n");

    /* 1. 리스트 초기화 */
    struct list my_list;
    if (init_list(&my_list) != 0) {
        fprintf(stderr, "[ERROR] 리스트 초기화 실패\n");
        return 1;
    }
    printf("[SUCCESS] 리스트 초기화 완료 (현재 isEmpty: %d)\n", is_empty(&my_list));

    /* 2. 테스트용 노드 생성 */
    struct node *n1 = create_node(10);
    struct node *n2 = create_node(20);
    struct node *n3 = create_node(30);
    struct node *n4 = create_node(40);

    /* 3. 삽입(Insert) API 테스트 */
    printf("\n--- 📥 Insert 테스트 ---\n");
    insert_last(&my_list, n1);   /* [10] */
    insert_last(&my_list, n2);   /* [10] - [20] */
    insert_first(&my_list, n3);  /* [30] - [10] - [20] */
    insert(&my_list, 1, n4);     /* [30] - [40] - [10] - [20] */
    printf("현재 리스트 Size: %d (예상: 4)\n", size(&my_list));

    /* 4. 이동(Move) API 테스트 */
    printf("\n--- 🚚 Move 테스트 ---\n");
    /* 노드 n1(10)을 맨 앞으로 -> [10] - [30] - [40] - [20] */
    move_first(&my_list, n1);
    
    /* 노드 n3(30)을 맨 뒤로 -> [10] - [40] - [20] - [30] */
    move_last(&my_list, n3);
    
    /* 노드 n2(20)를 인덱스 1로 -> [10] - [20] - [40] - [30] */
    move(&my_list, 1, n2);

    /* 5. 순회(For Each) API 테스트 */
    printf("\n--- 🖨️ For Each (전체 출력) 테스트 ---\n");
    /* v1 API의 for_each는 콜백 없이 내부에서 직접 printf를 수행한다고 가정 */
    for_each(&my_list);

    /* 6. 검색(Find) API 테스트 */
    printf("\n--- 🔍 Find 테스트 ---\n");
    int search_val = 40;
    struct node *found_node = find(&my_list, search_val);
    
    if (found_node) {
        printf("[Find 성공] 데이터 %d(을)를 가진 노드를 찾았습니다!\n", found_node->data);
    } else {
        printf("[Find 실패] 해당 데이터가 없습니다.\n");
    }

    /* 7. 삭제(Remove) API 테스트 (포인터 반환 적용) */
    printf("\n--- 📤 Remove & Memory Free 테스트 ---\n");
    struct node *removed_node;

    /* 첫 번째 노드 삭제 (예상: 10) */
    if ((removed_node = remove_first(&my_list))) {
        printf("[Remove First] Data: %d 삭제 완료\n", removed_node->data);
        free(removed_node); /* 동적 할당 해제 */
    }

    /* 마지막 노드 삭제 (예상: 30) */
    if ((removed_node = remove_last(&my_list))) {
        printf("[Remove Last]  Data: %d 삭제 완료\n", removed_node->data);
        free(removed_node);
    }

    /* 특정 인덱스(0) 삭제 (예상: 20) */
    /* 주의: C 표준 라이브러리의 remove() 함수와 이름 충돌이 발생할 수 있으므로 컴파일 시 유의 */
    if ((removed_node = remove_at(&my_list, 0))) {
        printf("[Remove Idx 0] Data: %d 삭제 완료\n", removed_node->data);
        free(removed_node);
    }

    /* 8. 리스트 정리 (Clear 및 Destroy) */
    printf("\n--- 🧹 Clear & Destroy 테스트 ---\n");
    
    /* 남아있는 노드들 정리 */
    clear(&my_list);
    
    /* 리스트 소멸자 호출 */
    destroy_list(&my_list);
    
    printf("🏁 모든 테스트 완료 및 객체 소멸 정상 처리.\n");

    return 0;
}