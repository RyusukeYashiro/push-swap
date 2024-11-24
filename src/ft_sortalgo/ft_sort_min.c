/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:46 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/23 20:10:38 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"

void ft_sort_three_a(t_stack **stack_a)
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
    //1 3 2
    else if(top < middle && bottom > top)
    {
        sa(stack_a);
        ra(stack_a);
    }
}

void ft_sort_three_b(t_stack **stack_b)
{
    int top;
    int middle;
    int bottom;
    t_node *first_b;
    
    first_b = (*stack_b) -> top;
    top = first_b -> value;
    middle = first_b -> next -> value;
    bottom = first_b -> next -> next -> value;

    if (top < middle && middle < bottom)
        return;
    //2 1 3
    else if(top > middle && top < bottom)
        sb(stack_b);
    //2 3 1
    else if(top < middle && top > bottom)
        rrb(stack_b);
    // 3 1 2
    else if(top > middle && top > bottom)
        rb(stack_b);
    //3 2 1
    else if(top > middle && middle > bottom)
    {   
        sb(stack_b);
        rrb(stack_b);
    }
    //1 3 2
    else if(top < middle && bottom > top)
    {
        sb(stack_b);
        rb(stack_b);
    }
}

void ft_sort_min_a(t_stack **stack_a ,int count)
{
    if (!stack_a || !*stack_a || !(*stack_a)->top)
        return;
    if(count == 2)
    {
        if (!(*stack_a)->top->next)
            return;
        if((*stack_a) -> top -> value < (*stack_a) -> top -> next -> value)
            return;
        else
            ra(stack_a);
    }
    else if (count == 3)
        ft_sort_three_a(stack_a);
}

void ft_sort_min_b(t_stack **stack_b, int count)
{
    if(!stack_b || !(*stack_b) || !(*stack_b) -> top)
        return;
    if(count == 2)
    {
        if(!(*stack_b) -> top -> next)
            return;
        if((*stack_b) -> top ->value < (*stack_b) -> top -> next -> value)
            return;
        else 
            rb(stack_b);
    }
    else if(count == 3)
        ft_sort_three_b(stack_b);
}

