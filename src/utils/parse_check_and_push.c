/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_and_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:29 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/12 10:39:17 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../include/push_swap.h"

bool	ft_double_check(int temp, char **args, int current_i)
{
	int	i;

	if (args[0] == NULL)
		i = 0;
	else
		i = 1;
	while (i < current_i)
	{
		if (ft_atoi(args[i]) == temp)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_numcheck(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_push(char **args, int *count, t_stack **stack_a, bool flag)
{
	long	temp;
	int		i;

	temp = 0;
	if (flag)
		i = 0;
	else
		i = 1;
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (free_split(args, flag), false);
		if (!ft_numcheck(args[i]) || !ft_double_check(temp, args, i))
			return (free_split(args, flag), false);
		(*count)++;
		ft_push_a(stack_a, temp);
		i++;
	}
	return (true);
}

int	ft_parse_check_and_push(int ac, char **av, t_stack **stack_a, int *count)
{
	char	**args;
	bool	flag;

	flag = false;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		flag = true;
		if (!args)
			return (1);
	}
	else
		args = av;
	if (!ft_check_push(args, count, stack_a, flag))
		return (1);
	if (flag)
		free_split(args, flag);
	return (0);
}
