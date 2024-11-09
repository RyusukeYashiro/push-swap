#include "../../include/push_swap.h"

void pa(t_stack **stack_a , t_stack **stack_b)
{
    t_node *node_elem;
    t_node *first_a;

    if(!stack_b || !(*stack_b) || !(*stack_b) -> top)
        return;
    if(!stack_a || !(*stack_a) || !(*stack_a) -> top)
        return;
    node_elem = (*stack_b) -> top;
    first_a = (*stack_a) -> top;
    if(node_elem -> next == node_elem)
        node_elem = NULL;
    else
    {
        node_elem -> next -> pre = node_elem -> pre;
        node_elem -> pre -> next = node_elem -> next;
        node_elem = node_elem ->next;
    }
    node_elem -> next = first_a;
    node_elem -> pre = first_a -> pre;
    first_a -> pre -> next = node_elem;
    first_a -> pre = node_elem;
    first_a = node_elem;
    write(1 , "pa\n" , 3);
}

void pb(t_stack **stack_a , t_stack **stack_b)
{
    t_node *node_elem;
    t_node *first_b;

     if(!stack_b || !(*stack_b) || !(*stack_b) -> top)
        return;
    if(!stack_a || !(*stack_a) || !(*stack_a) -> top)
        return;
    node_elem = (*stack_a) -> top;
    first_b = (*stack_b) -> top;
    if(node_elem -> next = node_elem)
        (*stack_a) -> top = NULL;
    else 
    {
        node_elem -> next -> pre = node_elem -> pre;
        node_elem -> pre -> next = node_elem -> next;
        node_elem = node_elem -> next;
    }
    node_elem -> next = first_b;
    node_elem -> pre = first_b -> pre;
    first_b -> pre -> next = node_elem;
    first_b -> pre = node_elem;
    first_b = node_elem;
    write(1 , "pb/n" , 3);
}
