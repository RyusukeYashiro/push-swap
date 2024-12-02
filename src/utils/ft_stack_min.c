/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:24 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 12:54:24 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_a_min(t_stack **stack_a)
{
	t_node	*temp;
	t_node	*first;
	int		min;

	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return (0);
	temp = (*stack_a)->top;
	first = temp;
	min = temp->value;
	temp = temp->next;
	while (temp != first)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}
