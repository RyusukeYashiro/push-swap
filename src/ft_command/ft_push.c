/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:21:01 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/12 18:20:42 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"


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
    (*stack_a) -> top = node_elem;
    ft_putendl_fd("pa" , 1);
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
    if(node_elem -> next == node_elem)
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
    (*stack_b) -> top = node_elem;
    ft_putendl_fd("pb" , 1);
}
