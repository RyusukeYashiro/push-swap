/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:33 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/10 18:10:13 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	ft_rotation_sort(t_stack **stack_a, int pos)
{
	int		min;
	int		stack_len;
	t_node	*temp;

	min = stack_a_min(stack_a);
	temp = (*stack_a)->top;
	stack_len = count_stack_len_a(stack_a);
	while (temp->value != min && temp->next != (*stack_a)->top)
	{
		pos++;
		temp = temp->next;
	}
	if (temp->value != min)
		return ;
	if (pos <= stack_len / 2)
	{
		while ((*stack_a)->top->value != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->top->value != min)
			rra(stack_a);
	}
}

void	ft_sort_check(int pos, int pos_len, t_stack **stack_a,
		t_stack **stack_b)
{
	int	rotations;

	if (pos == 0 || pos == pos_len)
		pa(stack_a, stack_b);
	else if (pos_len / 2 > pos)
	{
		rotations = pos;
		while (rotations > 0)
		{
			ra(stack_a);
			rotations--;
		}
		pa(stack_a, stack_b);
	}
	else
	{
		rotations = pos_len - pos;
		while (rotations > 0)
		{
			rra(stack_a);
			rotations--;
		}
		pa(stack_a, stack_b);
	}
}

void	ft_insert_sort(t_stack **stack_a, t_stack **stack_b, int num)
{
	t_node	*temp;
	int		pos;
	int		min;
	int		max;
	int		pos_len;

	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return ;
	temp = (*stack_a)->top;
	min = stack_a_min(stack_a);
	max = stack_a_max(stack_a);
	pos = 0;
	pos_len = count_stack_len_a(stack_a);
	if (num < min)
		pos = 0; 
	else if (num > max)
		pos = ft_find_pos_max(temp, stack_a, max);
	else
		pos = ft_find_pos_bt(temp, stack_a, num);
	if (pos >= pos_len)
		pos = 0;
	ft_sort_check(pos, pos_len, stack_a, stack_b);
	pos = 0;
	ft_rotation_sort(stack_a, pos);
}

void	ft_sort_mid(t_stack **a, t_stack **b, int count)
{
	int	insert_value;

	if (!a || !(*a) || !b || !(*b))
		return ;
	if (count == 4)
		pb(a , b);
	else if (count == 5)
	{
		pb(a, b);
		pb(a, b);
	}
	else if (count == 6)
	{
		pb(a, b);
		pb(a, b);
		pb(a, b);
	}
	ft_sort_three_a(a);
	while (*b && (*b)->top)
	{
		insert_value = (*b)->top->value;
		ft_insert_sort(a, b, insert_value);
	}
}
