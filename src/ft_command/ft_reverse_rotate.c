#include "../../include/push_swap.h"

void rra(t_stack **stack_a)
{
    t_node *first_a;

    if(!stack_a || !(*stack_a) || !((*stack_a) -> top))
        return;
    first_a = (*stack_a) -> top;
    if(first_a -> next == first_a)
        return;
    (*stack_a) -> top = first_a -> pre;
    write(1 , "rra\n" , 4);
}

void rrb(t_stack **stack_b)
{
    t_node *first_b;

    if(!stack_b || !(*stack_b) || !((*stack_b) -> top))
        return;
    first_b = (*stack_b) -> top;
    if(first_b -> next == first_b)
        return;
    (*stack_b) -> top = first_b -> pre;
    write(1 , "rrb\n" , 4);
}

void rrr(t_stack **stack_a , t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1, "rrr\n", 4);
}

