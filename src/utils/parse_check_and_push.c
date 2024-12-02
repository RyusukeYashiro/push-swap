/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_and_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:29 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 16:13:01 by ryusukeyash      ###   ########.fr       */
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

int	ft_parse_check_and_push(int ac, char **av, t_stack **stack_a, int *count)
{
	char	**args;
	int		i;
	long	temp;

	i = 1;
	if (ac == 2)
	{
		i = 0;
		args = ft_split(av[1], ' ');
		if (!args)
			return (1);
	}
	else
		args = av;
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (!ft_numcheck(args[i]) || !ft_double_check(temp, args, i))
			return (1);
		(*count)++;
		ft_push_a(stack_a, temp);
		i++;
	}
	return (0);
}
