/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:21:25 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/12 17:21:30 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    ft_putendl_fd("rra" , 1);
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
    ft_putendl_fd("rrb" , 1);
}

void rrr(t_stack **stack_a , t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_putendl_fd("rrr" , 1);
}

