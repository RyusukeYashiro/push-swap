/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:44 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/12 18:21:59 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

int ft_find_pivot(t_stack **stack , int size)
{
    t_node *temp;
    int i;
    int count;
    int middle_num;

    temp = (*stack) -> top;
    middle_num = temp -> value;
    i = 0;
    while(i < size)
    {
        count = 0;
        temp = (*stack) -> top;
        while(temp -> next != (*stack) -> top)
        {
            if(temp -> value < middle_num)
                count++;
            temp = temp -> next;
        }
        if(count == size / 2)
            return middle_num;
        temp = temp -> next;
        middle_num = temp -> value;
        i++;
    }
    return middle_num;
}

void ft_quick_sort(t_stack **stack_a , t_stack **stack_b , int len)
{
    int pivot;
    int i;
    int pb_size;

    pivot = ft_find_pivot(stack_a , len);
    i = 0;
    pb_size = 0;
    while(i < len)
    {
        if((*stack_a) -> top -> value < pivot)
        {
            pb(stack_a , stack_b);
            pb_size++;
        } else
            ra(stack_a);
        i++;
    }
    ft_quick_sort(stack_b , stack_a , pb_size);
    ft_quick_sort(stack_a , stack_b , len - pb_size);

    while(pb_size--)
    {
        rra(stack_b);
        pa(stack_a , stack_b);
    }
}

void ft_sort_stack(t_stack **a , t_stack **b , t_stack **hold , int count)
{
    if(count <= 3)
        ft_sort_min(a , count);
    else if (count <= 6)
        ft_sort_mid(a , b , count);
    else 
        ft_quick_sort(a , b ,count);
}
