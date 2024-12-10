/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:58:19 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/10 18:12:07 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"



int	ft_find_pos_max(t_node *temp, t_stack **a, int max)
{
	int	pos;

	pos = 0;
	if (temp->value == max)
		return (0);
	else
	{
		while (temp->value != max && temp->next != (*a)->top)
		{
			pos++;
			temp = temp->next;
		}
		pos++;
	}
	return (pos);
}

int	ft_find_pos_bt(t_node *temp, t_stack **a, int num)
{
	int	pos;

	pos = 0;
	while (temp->next != (*a)->top)
	{
		if (temp->value < num && temp->next->value > num)
		{
			pos++;
			break ;
		}
		pos++;
		temp = temp->next;
	}
	if (temp->next == (*a)->top && temp->value < num && (*a)->top->value > num)
		pos++;
	return (pos);
}
