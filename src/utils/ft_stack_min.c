#include "../../include/push_swap.h"

int stack_a_min(t_stack **stack_a)
{
    t_node *temp;
    int min;

    if (!stack_a || !*stack_a || !(*stack_a)->top)
        return (0);

    temp = (*stack_a)->top;
    min = temp->value;

    // 循環リストを最後まで探索
    while (temp->next != (*stack_a)->top)
    {
        if (temp->next->value < min)
            min = temp->next->value;
        temp = temp->next;
    }
    return (min);
}

int stack_b_min(t_stack **stack_b)
{
    t_node *temp;
    int min;

    if (!stack_b || !*stack_b || !(*stack_b)->top)
        return (0);

    temp = (*stack_b)->top;
    min = temp->value;

    // 循環リストを最後まで探索
    while (temp->next != (*stack_b)->top)
    {
        if (temp->next->value < min)
            min = temp->next->value;
        temp = temp->next;
    }
    return (min);
}