/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:44 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/24 15:49:10 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"
#include <stdio.h>
int ft_find_pivot(t_stack **stack , int size)
{
    t_node *temp;
    t_node *hold;
    int i;
    int count;

    temp = (*stack) -> top;
    i = 0;
    while(i < size)
    {
        count = 0;
        hold = (*stack) -> top;
        while(1)
        {
            if(hold -> value < temp -> value)
                count++;
            hold = hold -> next;
            if(hold == (*stack) -> top)
                break;
        }
        if(count == size / 2)
            return temp ->value;
        temp = temp -> next;
        i++;
    }
    return temp -> value;
}

void ft_quick_sort(t_stack **stack_a , t_stack **stack_b , int len)
{
    int pivot;
    int i;
    int pb_size;

    if(len <= 3)
    {
        ft_sort_min(stack_a , len);
        return;
    }
    pivot = ft_find_pivot(stack_a , len);
    printf("これがpivotとlenです : %d , %d\n" , pivot , len);
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
    printf("これは再起に入る前の処理です\n");
    print_stack_a(stack_a);
    print_stack_b(stack_b);
    ft_quick_sort(stack_b , stack_a , pb_size);
    ft_quick_sort(stack_a , stack_b , len - pb_size);
    while(pb_size--)
    {
        // rra(stack_b);
        pa(stack_a , stack_b);
    }
}

void ft_sort_stack(t_stack **a , t_stack **b , int count)
{
    printf("count : %d" , count);
    if(count <= 3)
    {
        ft_sort_min(a , count);
        printf("in min");
    }
    else if (4 <= count && count <= 6)
    {
        ft_sort_mid(a , b , count);
        printf("in mid");
    }
    else 
        ft_quick_sort(a , b ,count);
}
