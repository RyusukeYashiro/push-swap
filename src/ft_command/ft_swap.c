#include "../../include/push_swap.h"

void sa(t_stack **stack_a)
{
    t_node *first;
    t_node *second;

    if(!stack_a || !(*stack_a) || (*stack_a) -> top -> next == (*stack_a) -> top)
        return;
    first = (*stack_a) -> top;
    second = first ->next;
    //最初の次をnextの次へ
    first -> next = second -> next;
    first -> pre = second;

    second -> next = first;
    second -> pre = first -> pre;

    first -> next -> pre = first;
    (*stack_a) -> top = second;

    write(1 , "sa\n" , 3);
}

void sb(t_stack **stack_b)
{
    t_node *first;
    t_node *second;

    if(!stack_b || !(*stack_b) || (*stack_b) -> top -> next == (*stack_b) -> top)
        return;
    first = (*stack_b) -> top;
    second = first -> next;

    first -> next = second -> next;
    first -> pre = second;

    second -> next = first;
    second -> pre = first -> pre;

    first -> next -> pre = first;
    (*stack_b) -> top = second;

    write(1 , "sb/n" , 3);
}

void ss(t_stack **stack_a , t_stack **stack_b)
{
    if(!stack_a || !(*stack_a) || (*stack_a) -> top -> next == (*stack_a) -> top)
        return;
    if(!stack_b || !(*stack_b) || (*stack_b) -> top -> next == (*stack_b) -> top)
        return;
    sa(stack_a);
    sb(stack_b);
    write(1 , "ss\n" , 3);
}