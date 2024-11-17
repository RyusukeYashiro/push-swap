/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:46 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/17 00:53:11 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"

void ft_sort_three(t_stack **stack_a)
{
    int top;
    int middle;
    int bottom;
    t_node *first_a;
    
    first_a = (*stack_a) -> top;
    top = first_a -> value;
    middle = first_a -> next -> value;
    bottom = first_a -> next -> next -> value;

    if (top < middle && middle < bottom)
        return;
    //i 3 2
    else if(top < middle && middle > bottom)
    {
        sa(stack_a);
        ra(stack_a);
    }
    //2 1 3
    else if(top > middle && top < bottom)
        sa(stack_a);
    //2 3 1
    else if(top < middle && top > bottom)
        rra(stack_a);
    // 3 1 2
    else if(top > middle && top > bottom)
        ra(stack_a);
    //3 2 1
    else if(top > middle && middle > bottom)
    {   
        sa(stack_a);
        rra(stack_a);
    }
}


void ft_sort_min(t_stack **stack_a ,int count)
{
    if (!stack_a || !*stack_a || !(*stack_a)->top)
        return;
    if(count < 3)
    {
        if (!(*stack_a)->top->next)
            return;
        if((*stack_a) -> top -> value < (*stack_a) -> top -> next -> value)
            return;
        else
            ra(stack_a);
    }
    else if (count == 3)
        ft_sort_three(stack_a);
}