/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:19 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 19:28:03 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_a(t_stack **stack_a, int num)
{
	t_node	*newnode;
	t_node	*temp;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (free_stack(stack_a));
	newnode->value = num;
	if ((*stack_a)->top == NULL)
	{
		newnode->next = newnode;
		newnode->pre = newnode;
		(*stack_a)->top = newnode;
		return ;
	}
	temp = (*stack_a)->top;
	newnode->next = temp;
	newnode->pre = temp->pre;
	temp->pre->next = newnode;
	temp->pre = newnode;
}
