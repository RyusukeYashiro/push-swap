/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:21:01 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 19:15:44 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node_elem;

	node_elem = (*stack_b)->top;
	if (node_elem->next == node_elem)
		(*stack_b)->top = NULL;
	else
	{
		node_elem->next->pre = node_elem->pre;
		node_elem->pre->next = node_elem->next;
		(*stack_b)->top = node_elem->next;
	}
	if (!(*stack_a) || !(*stack_a)->top)
	{
		node_elem->next = node_elem;
		node_elem->pre = node_elem;
	}
	else
	{
		node_elem->next = (*stack_a)->top;
		node_elem->pre = (*stack_a)->top->pre;
		(*stack_a)->top->pre->next = node_elem;
		(*stack_a)->top->pre = node_elem;
	}
	(*stack_a)->top = node_elem;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node_elem;

	node_elem = (*stack_a)->top;
	if (node_elem->next == node_elem)
		(*stack_a)->top = NULL;
	else
	{
		node_elem->next->pre = node_elem->pre;
		node_elem->pre->next = node_elem->next;
		(*stack_a)->top = node_elem->next;
	}
	if (!(*stack_b) || !(*stack_b)->top)
	{
		node_elem->next = node_elem;
		node_elem->pre = node_elem;
	}
	else
	{
		node_elem->next = (*stack_b)->top;
		node_elem->pre = (*stack_b)->top->pre;
		(*stack_b)->top->pre->next = node_elem;
		(*stack_b)->top->pre = node_elem;
	}
	(*stack_b)->top = node_elem;
	ft_putendl_fd("pb", 1);
}
