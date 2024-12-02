/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:52:32 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 12:52:36 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	ft_issorted(t_stack *a)
{
	t_node	*temp;

	temp = a->top;
	while (1)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
		if (temp->next == a->top)
			break ;
	}
	return (true);
}
