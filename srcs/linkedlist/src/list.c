#include <stdlib.h>
#include "../include/list.h"
#include "_internal.h"

/**
 * @brief   함수 포인터 테이블
 * @details static으로 하나만 생성 -> 메모리 절약
 */
static const list_ops_t _ops = {
    .is_empty     = is_empty_impl,
    .size         = size_impl,
    .find         = find_impl,
    .for_each     = for_each_impl,
    
    .insert       = insert_impl,
    .insert_first = insert_first_impl,
    .insert_last  = insert_last_impl,
    
    .remove       = remove_impl,
    .remove_first = remove_first_impl,
    .remove_last  = remove_last_impl,
    
    .move         = move_impl,
    .move_first   = move_first_impl,
    .move_last    = move_last_impl,
    
    .clear        = clear_impl
};

int init_list(list_t* const list)
{
    return 0;
}

int destroy_list(list_t* const list, void (*free_func)(list_node_t*))
{
    return 0;
}