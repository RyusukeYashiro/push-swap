/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:39 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/02 19:46:53 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/push_swap.h"
#include "stdio.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->top = NULL;
	return (new_stack);
}

void	print_stack_a(t_stack **stack_a)
{
	t_node	*temp;
	t_node	*first;

	temp = (*stack_a)->top;
	first = temp;
	printf("%s\n", "this is stack_a");
	printf("%d ", temp->value);
	temp = temp->next;
	while (temp != first)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void	print_stack_b(t_stack **stack_b)
{
	t_node	*temp;
	t_node	*first;

	temp = (*stack_b)->top;
	first = temp;
	// printf("%s\n", "this is stack_b");
	printf("%d ", temp->value);
	temp = temp->next;
	while (temp != first)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

// __attribute__((destructor)) static void a(void)
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

	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (!stack_a || !stack_b)
		return (0);
	count = 0;
	error_flag = ft_parse_check_and_push(ac, av, &stack_a, &count);
	if (error_flag == 1)
	{
		ft_putstr_fd("Error", 1);
		return (free_stack(&stack_a), free_stack(&stack_b), 0);
	}
	sorted_flag = ft_issorted(stack_a);
	if (sorted_flag)
		return (free_stack(&stack_a), 0);
	ft_sort_stack(&stack_a, &stack_b, count);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
