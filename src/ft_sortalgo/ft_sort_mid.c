/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:33 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/12 17:22:40 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void ft_rotation_sort(t_stack **stack_a , int min)
{
    int pos;
    t_node *temp;

    pos = 0;
    temp = (*stack_a) -> top;
    while(temp -> value != min)
    {
        pos++;
        temp = temp -> next;
    }
    if (pos <= count_stack_len(stack_a) / 2)
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

void ft_sort_check(int pos, int pos_len , t_stack **stack_a , t_stack **stack_b)
{
    // 最初と最後だったらローテンションさせない
    if(pos == 0 || pos == pos_len)
        pa(stack_a , stack_b);
    else if (pos_len / 2 > pos)
    {
        //ありうる位置の場所の半分割より小さい区間の場合は前へ移動
        while(pos > 0)
        {
            ra(stack_a);
            pos--;
        }
        pa(stack_a , stack_b);
    }
    else if (pos_len / 2 <= pos)
    {
        while(pos_len - pos > 0)
        {
            rra(stack_a);
            pos++;
        }
        pa(stack_a , stack_b);
    }
}

void ft_insert_sort(t_stack **stack_a , t_stack **stack_b , int num , int count)
{
    t_node *temp;
    //挿入するのはpos+1の箇所
    int pos;
    int min;
    int pos_len;

    temp = (*stack_a) -> top;
    min = stack_a_min(stack_a);
    pos = 0;
    pos_len = count_stack_len(stack_a);
    //一旦ここで挿入すべき箇所を見つける
    while(temp -> next != (*stack_a) -> top)
    {
        if((temp -> value < num && temp -> next -> value > num)
            || (temp -> value > num && temp -> next ->value == min))
        {
            pos++;
            break;
        }
        pos++;
        temp = temp -> next;
    }
    ft_sort_check(pos , pos_len , stack_a , stack_b);
    ft_rotation_sort(stack_a , min);
}

void ft_sort_mid(t_stack **a  , t_stack **b , int count)
{
    int insert_value;

    if(!a || !(*a) || !b || !(*b))
        return;
    if(count == 4 || count == 5)
    {
        pb(a , b);
        pb(a , b);
    }
    else if (count == 6)
    {
        pb(a , b);
        pb(a , b);
        pb(a , b);
    }
    ft_sort_three(a);
    //bをひたすら前から貪欲に挿入していく
    while(*b)
    {
        insert_value = (*b) -> top -> value;
        ft_insert_sort(a , b , insert_value , count);    
    }
}