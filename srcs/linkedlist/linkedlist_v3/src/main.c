#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/list.h"

/* -------------------------------------------------------------------------
 * 1. 사용자 정의 구조체 및 콜백 함수 세팅
 * ------------------------------------------------------------------------- */
struct student {
    int id;
    char name[32];
    struct node node; /* 리스트와 연결될 핵심 부품 (임베딩) */
};

/* [헬퍼] 학생 데이터 동적 할당 */
struct student* create_student(int id, const char* name)
{
    struct student *stu = (struct student *)malloc(sizeof(struct student));
    stu->id = id;
    strncpy(stu->name, name, sizeof(stu->name) - 1);
    stu->name[sizeof(stu->name) - 1] = '\0';
    
    stu->node.prev = NULL;
    stu->node.next = NULL;
    
    return stu;
}

/* [콜백] 노드 메모리 해제용 */
void free_student_node(struct node *node) 
{
    struct student *target = container_of(node, struct student, node);
    printf("  -> [자동 정리] ID: %d, Name: %s 메모리 해제\n", target->id, target->name);
    free(target);
}

/* [콜백] for_each를 위한 출력 함수 */
void print_student_node(struct node *node)
{
    struct student *stu = container_of(node, struct student, node);
    printf("  [학생 정보] ID: %d, Name: %s\n", stu->id, stu->name);
}

/* [콜백] find를 위한 조건 검색 (ID 비교) */
int compare_student_id(struct node *node, void *arg)
{
    struct student *stu = container_of(node, struct student, node);
    int target_id = *(int *)arg; /* void* 로 넘어온 값을 int로 캐스팅 */
    return (stu->id == target_id) ? 1 : 0; /* 일치하면 1 반환 */
}

/* -------------------------------------------------------------------------
 * 2. 메인 테스트 로직
 * ------------------------------------------------------------------------- */
int main(void)
{
    printf("🚀 VEDA Linked List ADT 테스트 시작\n\n");

    /* 1. 리스트 초기화 */
    struct list my_list;
    if (init_list(&my_list) != 0) {
        fprintf(stderr, "[ERROR] 리스트 초기화 실패\n");
        return 1;
    }
    printf("[SUCCESS] 리스트 초기화 완료\n");

    /* 2. 테스트용 데이터 생성 */
    struct student *s1 = create_student(101, "Alice");
    struct student *s2 = create_student(102, "Bob");
    struct student *s3 = create_student(103, "Charlie");
    struct student *s4 = create_student(104, "Dave");

    /* 3. 삽입(Insert) API 테스트 */
    printf("\n--- 📥 Insert 테스트 ---\n");
    my_list.ops->insert_last(&my_list, &s1->node);   /* [Alice] */
    my_list.ops->insert_last(&my_list, &s2->node);   /* [Alice] - [Bob] */
    my_list.ops->insert_first(&my_list, &s3->node);  /* [Charlie] - [Alice] - [Bob] */
    my_list.ops->insert(&my_list, 1, &s4->node);     /* [Charlie] - [Dave] - [Alice] - [Bob] */
    printf("현재 리스트 Size: %d (예상: 4)\n", my_list.ops->size(&my_list));

    /* 4. 이동(Move) API 테스트 */
    printf("\n--- 🚚 Move 테스트 ---\n");
    /* Alice를 맨 앞으로 -> [Alice] - [Charlie] - [Dave] - [Bob] */
    my_list.ops->move_first(&my_list, &s1->node);
    
    /* Charlie를 맨 뒤로 -> [Alice] - [Dave] - [Bob] - [Charlie] */
    my_list.ops->move_last(&my_list, &s3->node);

    /* 5. 순회(For Each) API 테스트 */
    printf("\n--- 🖨️ For Each (전체 출력) 테스트 ---\n");
    my_list.ops->for_each(&my_list, print_student_node);

    /* 6. 검색(Find) API 테스트 */
    printf("\n--- 🔍 Find 테스트 ---\n");
    int search_id = 102; /* Bob 찾기 */
    struct node *found_node = my_list.ops->find(&my_list, compare_student_id, &search_id);
    
    if (found_node) {
        struct student *found_stu = container_of(found_node, struct student, node);
        printf("[Find 성공] ID %d 학생을 찾았습니다! 이름: %s\n", search_id, found_stu->name);
    } else {
        printf("[Find 실패] 해당 학생이 없습니다.\n");
    }

    /* 7. 삭제(Remove) API 테스트 (리눅스 커널 스타일 포인터 반환 적용) */
    printf("\n--- 📤 Remove & Memory Free 테스트 ---\n");
    struct node *removed_node;
    struct student *target;

    /* 첫 번째 노드 삭제 (예상: Alice) */
    if ((removed_node = my_list.ops->remove_first(&my_list))) {
        target = container_of(removed_node, struct student, node);
        printf("[Remove First] ID: %d, Name: %s 삭제\n", target->id, target->name);
        free(target); /* 사용자가 직접 해제 */
    }

    /* 마지막 노드 삭제 (예상: Charlie) */
    if ((removed_node = my_list.ops->remove_last(&my_list))) {
        target = container_of(removed_node, struct student, node);
        printf("[Remove Last]  ID: %d, Name: %s 삭제\n", target->id, target->name);
        free(target);
    }

    /* 특정 인덱스(0) 삭제 (예상: Dave) */
    if ((removed_node = my_list.ops->remove(&my_list, 0))) {
        target = container_of(removed_node, struct student, node);
        printf("[Remove Idx 0] ID: %d, Name: %s 삭제\n", target->id, target->name);
        free(target);
    }

    /* 8. 리스트 정리 (Clear 및 Destroy) */
    printf("\n--- 🧹 Clear & Destroy 테스트 ---\n");

    destroy_list(&my_list, free_student_node);
    
    printf("🏁 모든 테스트 완료 및 객체 소멸 정상 처리.\n");

    return 0;
}