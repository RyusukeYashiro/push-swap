/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:58 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/09 23:58:18 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_node	*temp;
	t_node	*first;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	if ((*stack)->top)
	{
		temp = (*stack)->top;
		if (temp->next == temp)
			free(temp);
		else
		{
			first = temp;
			while (temp->next != first)
			{
				next = temp->next;
				free(temp);
				temp = next;
			}
			free(temp);
		}
	}
	free(*stack);
	*stack = NULL;
}

void	free_split(char **args, bool flag)
{
	int	i;

	if (flag)
		i = 0;
	else
		i = 1;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
