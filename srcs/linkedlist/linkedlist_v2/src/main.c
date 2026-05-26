#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

/* -------------------------------------------------------------------------
 * 1. 헬퍼 함수 및 콜백 함수 세팅
 * ------------------------------------------------------------------------- */
/* [헬퍼] 테스트용 정수 데이터 동적 할당 */
int* create_data(int val)
{
    int *p = (int *)malloc(sizeof(int));
    if (!p) {
        fprintf(stderr, "[ERROR] 메모리 할당 실패\n");
        exit(1);
    }
    *p = val;
    return p;
}

/* [콜백] find를 위한 조건 검색 (값 비교) */
int compare_int(void *data, void *arg)
{
    if (data == NULL || arg == NULL) return 0;
    
    int node_val = *(int *)data;
    int target_val = *(int *)arg; // arg로 넘어온 값을 int로 캐스팅
    
    return (node_val == target_val) ? 1 : 0; // 일치하면 1 반환
}

/* [콜백] clear를 위한 메모리 해제 함수 */
void free_data(void *data)
{
    if (data) {
        printf("  -> [자동 정리] 데이터 %d 메모리 해제\n", *(int *)data);
        free(data);
    }
}

/* [헬퍼] 리스트 전체 출력 (API에 for_each가 없으므로 직접 노드 순회) */
void print_list(const struct list* const l)
{
    printf("  현재 상태 [Size: %d]: ", size(l));
    struct node *curr = l->head;
    while (curr != NULL) {
        printf("[%d] -> ", *(int *)(curr->data));
        curr = curr->next;
    }
    printf("NULL\n");
}

/* -------------------------------------------------------------------------
 * 2. 메인 테스트 로직
 * ------------------------------------------------------------------------- */
int main(void)
{
    printf("🚀 VEDA Linked List (v2 - void* Generic with Callbacks) ADT 테스트 시작\n\n");

    /* 1. 리스트 초기화 */
    struct list my_list;
    if (init_list(&my_list) != 0) {
        fprintf(stderr, "[ERROR] 리스트 초기화 실패\n");
        return 1;
    }
    printf("[SUCCESS] 리스트 초기화 완료 (isEmpty: %d)\n", is_empty(&my_list));

    /* 2. 동적 데이터 생성 및 삽입 */
    printf("\n--- 📥 Insert 테스트 ---\n");
    insert_last(&my_list, create_data(10));   /* [10] */
    insert_last(&my_list, create_data(20));   /* [10] -> [20] */
    insert_first(&my_list, create_data(30));  /* [30] -> [10] -> [20] */
    insert(&my_list, 1, create_data(40));     /* [30] -> [40] -> [10] -> [20] */
    print_list(&my_list);

    /* 3. 이동(Move) API 테스트 */
    printf("\n--- 🚚 Move 테스트 ---\n");
    move_first(&my_list, 2); /* 인덱스 2(10)를 맨 앞으로 */
    move_last(&my_list, 1);  /* 인덱스 1(30)을 맨 뒤로 */
    move(&my_list, 2, 1);    /* 인덱스 2(20)를 인덱스 1로 */
    
    printf("이동 결과:\n");
    print_list(&my_list);    /* 예상: [10] -> [20] -> [40] -> [30] */

    /* 4. 검색(Find) API 테스트 (콜백 함수 적용) */
    printf("\n--- 🔍 Find 테스트 ---\n");
    int target = 40; 
    /* 이전과 달리 주소(d4)가 아닌 값(target)을 넘겨서 검색 가능해짐! */
    int found_idx = find(&my_list, compare_int, &target);
    
    if (found_idx != -1) {
        printf("[Find 성공] 값 %d을(를) 가진 노드의 인덱스는 %d입니다.\n", target, found_idx);
    } else {
        printf("[Find 실패] 데이터를 찾지 못했습니다.\n");
    }

    /* 5. 삭제(Remove) API 테스트 */
    printf("\n--- 📤 Remove 테스트 ---\n");
    void *removed_data = NULL;

    /* 첫 번째 삭제 (예상: 10) */
    removed_data = remove_first(&my_list);
    if (removed_data) {
        printf("[Remove First] 데이터 삭제 완료: %d\n", *(int *)removed_data);
        free(removed_data); /* 반환받은 단일 데이터는 수동 해제 */
    }

    /* 특정 인덱스(0) 삭제 (예상: 20) */
    removed_data = remove_at(&my_list, 0);
    if (removed_data) {
        printf("[Remove Idx 0] 데이터 삭제 완료: %d\n", *(int *)removed_data);
        free(removed_data); /* 반환받은 단일 데이터는 수동 해제 */
    }

    print_list(&my_list); /* 남은 건 [40] -> [30] 이어야 함 */

    /* 6. 리스트 정리 (Clear 및 Destroy - 콜백 함수 적용) */
    printf("\n--- 🧹 Clear & Destroy 테스트 ---\n");
    
    /* [개선된 부분] 남은 [40], [30] 데이터가 free_data 콜백을 통해 자동으로 메모리 해제됨 */
    clear(&my_list, free_data);
    
    /* 리스트 소멸 */
    destroy_list(&my_list);
    
    printf("\n🏁 모든 테스트 완료. 콜백을 이용한 메모리 정리가 정상 수행되었습니다.\n");

    return 0;
}