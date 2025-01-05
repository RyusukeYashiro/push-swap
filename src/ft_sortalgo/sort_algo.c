/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:44 by ryusukeyash       #+#    #+#             */
/*   Updated: 2025/01/05 17:10:25 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"
#include <stdio.h>

int	ft_digit(int num)
{
	int	result;

	result = 0;
	num -= 1;
	while ((num >> result) != 0)
		result++;
	return (result);
}

int	ft_find_index(t_stack **stack, int *array, int len)
{
	t_node	*temp;
	t_node	*elem;
	int		i;
	int		result;

	temp = (*stack)->top;
	i = 0;
	while (i < len)
	{
		result = 0;
		elem = (*stack)->top;
		while (1)
		{
			if (temp->value > elem->value)
				result++;
			elem = elem->next;
			if (elem == (*stack)->top)
				break ;
		}
		array[i] = result;
		temp = temp->next;
		i++;
	}
	return (ft_digit(len));
}

void	ft_radix_sort(t_stack **a, t_stack **b, int len, int bit)
{
	int	mx_bit_size;
	int	*array;
	int	j;

	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return ;
	mx_bit_size = ft_find_index(a, array, len);
	while (bit < mx_bit_size)
	{
		j = 0;
		while (j < len)
		{
			if (((array[j] >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while ((*b)->top)
			pa(a, b);
		ft_find_index(a, array, len);
		bit++;
	}
	free(array);
}

void	ft_sort_stack(t_stack **a, t_stack **b, int count)
{
	int	bit;

	bit = 0;
	if (count <= 3)
	{
		ft_sort_min_a(a, count);
	}
	else if (4 <= count && count <= 6)
	{
		ft_sort_mid(a, b, count);
	}
	else
		ft_radix_sort(a, b, count, bit);
}
