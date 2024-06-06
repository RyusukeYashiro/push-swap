#include "../include/push_swap.h"

void free_stack(t_stack **stack)
{
    t_node *temp;
    t_node *next;
    t_node *first;

    //stackはここでは**stackのことを指す。
    if(stack == NULL || *stack == NULL)
        return;
    temp = (*stack) -> top;
    //stackが1つの時の処理。つまりこの一つの要素を解放すれば良い。
    //*stackはt_stack **stack がさす実際のスタック構造(スタック構造へのポインタ)を指す。
    if(temp -> next == temp)
    {
        free(temp);
        free(*stack);
        *stack = NULL;
        return;
    }
    //最初の位置を保持しておく関数
    first = temp;
    while(temp -> next != first)
    {
        next = temp -> next;
        free(temp);
        temp = next;
    }
    free(temp);
    free(*stack);
    *stack = NULL;
}