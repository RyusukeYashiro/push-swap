/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_stack_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:08 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 12:07:14 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	count_stack_len_a(t_stack **stack_a)
{
	t_node	*temp;
	int		len;

	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return (0);
	if (!(*stack_a)->top)
		return (0);
	if ((*stack_a)->top->next == (*stack_a)->top)
		return (1);
	temp = (*stack_a)->top;
	len = 1;
	while (temp->next != (*stack_a)->top)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	count_stack_len_b(t_stack **stack_b)
{
	t_node	*temp;
	int		len;

	if (!stack_b || !*stack_b || !(*stack_b)->top)
		return (0);
	if (!(*stack_b)->top)
		return (0);
	if ((*stack_b)->top->next == (*stack_b)->top)
		return (1);
	temp = (*stack_b)->top;
	len = 1;
	while (temp->next != (*stack_b)->top)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
