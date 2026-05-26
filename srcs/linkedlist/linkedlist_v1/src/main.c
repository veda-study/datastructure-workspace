#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

/* -------------------------------------------------------------------------
 * 메인 테스트 로직 (v1 - 데이터 중심 캡슐화 방식)
 * ------------------------------------------------------------------------- */
int main(void)
{
    printf("🚀 VEDA Linked List (v1 - Encapsulated Data) ADT 테스트 시작\n\n");

    /* 1. 리스트 초기화 */
    struct list my_list;
    if (init_list(&my_list) != 0) {
        fprintf(stderr, "[ERROR] 리스트 초기화 실패\n");
        return 1;
    }
    printf("[SUCCESS] 리스트 초기화 완료 (현재 isEmpty: %d)\n", is_empty(&my_list));

    /* 2. 삽입(Insert) API 테스트 */
    printf("\n--- 📥 Insert 테스트 ---\n");
    insert_last(&my_list, 10);   /* [10] */
    insert_last(&my_list, 20);   /* [10] - [20] */
    insert_first(&my_list, 30);  /* [30] - [10] - [20] */
    insert(&my_list, 1, 40);     /* [30] - [40] - [10] - [20] */
    printf("현재 리스트 Size: %d (예상: 4)\n", size(&my_list));

    /* 3. 이동(Move) API 테스트 (Index 기반) */
    printf("\n--- 🚚 Move 테스트 ---\n");
    /* 초기 상태: [30] - [40] - [10] - [20] */
    
    /* 인덱스 2에 있는 값(10)을 맨 앞으로 -> [10] - [30] - [40] - [20] */
    move_first(&my_list, 2);
    
    /* 인덱스 1에 있는 값(30)을 맨 뒤로 -> [10] - [40] - [20] - [30] */
    move_last(&my_list, 1);
    
    /* 인덱스 2에 있는 값(20)을 인덱스 1로 -> [10] - [20] - [40] - [30] */
    move(&my_list, 2, 1);

    /* 4. 순회(For Each) API 테스트 */
    printf("\n--- 🖨️ For Each (전체 출력) 테스트 ---\n");
    /* 예상 출력: 10 -> 20 -> 40 -> 30 */
    for_each(&my_list);

    /* 5. 검색(Find) API 테스트 */
    printf("\n--- 🔍 Find 테스트 ---\n");
    int search_val = 40;
    struct node *found_node = find(&my_list, search_val);
    
    if (found_node) {
        printf("[Find 성공] 데이터 %d(을)를 가진 노드를 찾았습니다!\n", found_node->data);
    } else {
        printf("[Find 실패] 해당 데이터가 없습니다.\n");
    }

    /* 6. 삭제(Remove) API 테스트 (Data 값 반환 적용) */
    printf("\n--- 📤 Remove 테스트 ---\n");
    /* * 주의: 메모리 해제(free)는 remove 계열 함수 내부에서 자체적으로 수행되어야 합니다.
     * 외부로 반환되는 것은 지워진 노드의 '데이터(int)'뿐입니다.
     */
    int removed_val;

    /* 첫 번째 노드 삭제 (예상: 10) */
    removed_val = remove_first(&my_list);
    printf("[Remove First] 반환된 Data: %d 삭제 완료\n", removed_val);

    /* 마지막 노드 삭제 (예상: 30) */
    removed_val = remove_last(&my_list);
    printf("[Remove Last]  반환된 Data: %d 삭제 완료\n", removed_val);

    /* 특정 인덱스(0) 삭제 (예상: 20) */
    removed_val = remove_at(&my_list, 0);
    printf("[Remove Idx 0] 반환된 Data: %d 삭제 완료\n", removed_val);

    /* 7. 리스트 정리 (Clear 및 Destroy) */
    printf("\n--- 🧹 Clear & Destroy 테스트 ---\n");
    
    /* 남아있는 노드들 정리 */
    clear(&my_list);
    
    /* 리스트 소멸자 호출 */
    destroy_list(&my_list);
    
    printf("🏁 모든 테스트 완료 및 객체 소멸 정상 처리.\n");

    return 0;
}