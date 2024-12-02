/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:53:32 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 12:53:39 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_a_max(t_stack **stack_a)
{
	t_node	*temp;
	t_node	*first;
	int		max;

	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return (0);
	temp = (*stack_a)->top;
	first = temp;
	max = temp->value;
	temp = temp->next;
	while (temp != first)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}
