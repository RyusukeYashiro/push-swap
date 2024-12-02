/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:46 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 18:06:54 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	ft_check(int tp, int md, int bm, t_stack **a)
{
	if (tp < md && md < bm)
		return ;
	else if (tp > md && tp < bm)
		sa(a);
	else if (tp < md && tp > bm)
		rra(a);
	else if (tp > md && bm > md)
		ra(a);
	else if (tp > md && md > bm)
	{
		sa(a);
		rra(a);
	}
	else if (tp < md && bm > tp)
	{
		sa(a);
		ra(a);
	}
}

void	ft_sort_three_a(t_stack **stack_a)
{
	int		tp;
	int		md;
	int		bm;
	t_node	*first_a;

	first_a = (*stack_a)->top;
	tp = first_a->value;
	md = first_a->next->value;
	bm = first_a->next->next->value;
	ft_check(tp, md, bm, stack_a);
}

void	ft_sort_min_a(t_stack **stack_a, int count)
{
	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return ;
	if (count == 2)
	{
		if (!(*stack_a)->top->next)
			return ;
		if ((*stack_a)->top->value < (*stack_a)->top->next->value)
			return ;
		else
			ra(stack_a);
	}
	else if (count == 3)
		ft_sort_three_a(stack_a);
}
