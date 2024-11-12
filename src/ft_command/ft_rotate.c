/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:21:38 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/12 17:21:44 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    ft_putendl_fd("ra" , 1);
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
    ft_putendl_fd("ra" , 1);
}

void rr(t_stack **stack_a , t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    ft_putendl_fd("rr" , 1);
}