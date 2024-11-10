#include "../../include/push_swap.h"

void ra(t_stack **stack_a)
{
    t_node *first_a;

    if(!stack_a || !(*stack_a) || !((*stack_a) -> top))
        return;
    first_a = (*stack_a) -> top;
    if(first_a -> next == first_a)
        return;
    
    (*stack_a) -> top = first_a -> next;
    write(1 , "ra\n" , 3);
}

void rb(t_stack **stack_b)
{
    t_node *first_b;

    if(!stack_b || !(*stack_b) || !((*stack_b) -> top))
        return;
    first_b = (*stack_b) -> top;
    if(first_b -> next == first_b)
        return;
    
    (*stack_b) -> top = first_b -> next;
    write(1 , "rb\n" , 3);
}

void rr(t_stack **stack_a , t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);
}