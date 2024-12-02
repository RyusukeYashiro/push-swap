/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:58 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 12:07:25 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_node	*temp;
	t_node	*first;
	t_node	*next;

	if (!stack || !*stack || !(*stack)->top)
		return ;
	temp = (*stack)->top;
	if (temp->next == temp)
	{
		free(temp);
		free(*stack);
		*stack = NULL;
		return ;
	}
	first = temp;
	while (temp->next != first)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(temp);
	free(*stack);
	*stack = NULL;
}
