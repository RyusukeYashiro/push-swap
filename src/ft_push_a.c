#include "../include/push_swap.h"

void ft_push_a(t_stack **stack_a , int  num)
{
    t_node *newNode = malloc(sizeof(t_node));
    
    if(newNode == NULL)
    {
        free_stack(stack_a);
        return ;
    }
    newNode -> value = num;
    if((*stack_a) -> top == NULL)
    {
        newNode -> next = newNode;
        newNode -> pre = newNode;
        (*stack_a) -> top = newNode;
        return;
    }
    newNode -> next = (*stack_a) -> top;
    newNode -> pre = (*stack_a) -> top -> pre;
    (*stack_a) -> top -> pre -> next = newNode;
    (*stack_a) -> top -> pre = newNode; 
}