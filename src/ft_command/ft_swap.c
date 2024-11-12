/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:03 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/12 17:22:12 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    ft_putendl_fd("sa" , 1);
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

    ft_putendl_fd("sb" , 1);
}

void ss(t_stack **stack_a , t_stack **stack_b)
{
    if(!stack_a || !(*stack_a) || (*stack_a) -> top -> next == (*stack_a) -> top)
        return;
    if(!stack_b || !(*stack_b) || (*stack_b) -> top -> next == (*stack_b) -> top)
        return;
    sa(stack_a);
    sb(stack_b);
    ft_putendl_fd("ss" , 1);
}