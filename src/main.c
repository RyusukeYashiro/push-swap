/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryyashir <ryyashir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:39 by ryusukeyash       #+#    #+#             */
/*   Updated: 2025/01/05 17:08:51 by ryyashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"
#include "stdio.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	return (new_stack);
}

// __attribute__((destructor)) static void destructor(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	bool	sorted_flag;
	int		error_flag;
	int		count;

	if (ac == 1)
		return (0);
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (!stack_a || !stack_b)
		return (0);
	count = 0;
	error_flag = ft_parse_check_and_push(ac, av, &stack_a, &count);
	if (error_flag == 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (free_stack(&stack_a), free_stack(&stack_b), 0);
	}
	sorted_flag = ft_issorted(stack_a);
	if (sorted_flag)
		return (free_stack(&stack_a), free_stack(&stack_b), 0);
	ft_sort_stack(&stack_a, &stack_b, count);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
