#include "../include/push_swap.h"

void ft_push_a(t_stack **stack_a , int  num)
{
    t_node *newNode;
    t_node *temp;
    
    newNode = malloc(sizeof(t_node));
    if(newNode == NULL)
    {
        free_stack(stack_a);
        return ;
    }
    newNode -> value = num;
    // stackがからの場合
    if((*stack_a) -> top == NULL)
    {
        newNode -> next = newNode;
        newNode -> pre = newNode;
        (*stack_a) -> top = newNode;
        return;
    }
    // 先頭と末尾の両方のポインタを更新して循環構造を保つ
    temp = (*stack_a) -> top;
    //新しいノードが現在のtop
    newNode -> next = temp;
    //前のノードが現在のノードの１つ前
    newNode -> pre = temp -> pre;
    temp -> pre -> next = newNode;
    temp -> pre = newNode; 
}