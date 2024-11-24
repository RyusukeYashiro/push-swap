/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:33 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/23 21:21:06 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"

// 最小値が前にあると、効率的に先頭に移動できる
void ft_rotation_sort(t_stack **stack_a)
{
    int pos;
    int min;
    int stack_len;
    t_node *temp;

    if (!stack_a || !(*stack_a) || !(*stack_a)->top)
        return;
    min = stack_a_min(stack_a); 
    pos = 0;
    temp = (*stack_a)->top;
    stack_len = count_stack_len_a(stack_a);

    // 最小値の位置を探す
    while (temp->value != min && temp->next != (*stack_a)->top)
    {
        pos++;
        temp = temp->next;
    }

    // 最小値が見つからない場合は何もしない
    if (temp->value != min)
        return;
    // 最小値がスタックの上に来るまで回転
    // 挿入位置が半分より前
    if (pos <= stack_len / 2)
    {
        while ((*stack_a)->top->value != min)
            ra(stack_a);
    }
    //挿入位置が半分より後ろ
    else
    {
        while ((*stack_a)->top->value != min)
            rra(stack_a);
    }
}


void ft_sort_check(int pos, int pos_len, t_stack **stack_a, t_stack **stack_b)
{
    int rotations;

    // 最初と最後だったらローテンションさせない
    if (pos == 0 || pos == pos_len)
        pa(stack_a, stack_b);
    else if (pos_len / 2 > pos)
    {
        rotations = pos;
        while (rotations > 0)
        {
            ra(stack_a);
            rotations--;
        }
        pa(stack_a, stack_b);
    }
    else
    {
        rotations = pos_len - pos;
        while (rotations > 0)
        {
            rra(stack_a);
            rotations--;
        }
        pa(stack_a, stack_b);
    }
}

void ft_insert_sort(t_stack **stack_a, t_stack **stack_b, int num)
{
    t_node *temp;
    int pos;
    int min;
    int max;
    int pos_len;
    
    if (!stack_a || !*stack_a || !(*stack_a)->top)
        return;
    temp = (*stack_a)->top;
    min = stack_a_min(stack_a);
    max = stack_a_max(stack_a);
    pos = 0;
    pos_len = count_stack_len_a(stack_a);

    // 最小値より小さい場合は最小値の前に挿入する処理
    if (num < min)
    {
        // 最小値が先頭にある場合
        if(temp -> value == min)
            pos = 0;
        else
        {
            while(temp -> value != min && temp -> next != (*stack_a) -> top)
            {
                pos++;
                temp = temp -> next;
            }
        }
    }
    // 最大値より大きい場合は最大値の後に挿入
    else if (num > max)
    {
        // 最大値が先頭にある場合
        if (temp->value == max)
            pos = 1;
        else 
        {
            while (temp->value != max && temp->next != (*stack_a)->top)
            {
                pos++;
                temp = temp->next;
            }
            //そのmaxの次に入れる必要があるから
            pos++;
        }
    }
    // その他の場合、適切な位置を探す
    else
    {
            while (temp->next != (*stack_a)->top)
            {
                if (temp->value < num && temp->next->value > num)
                {
                    pos++;
                    break;
                }
                pos++;
                temp = temp->next;
            }
            // 最後のノードの後ろに入る場合
            if (temp->next == (*stack_a)->top && 
                temp->value < num && (*stack_a)->top->value > num)
            {
                pos++;
            }
    }

    // 正しい位置が見つからなかった場合のデフォルト動作
    if (pos >= pos_len)
        pos = 0;

    ft_sort_check(pos, pos_len, stack_a, stack_b);
    ft_rotation_sort(stack_a);
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
    ft_sort_three_a(a);
    //bをひたすら前から貪欲に挿入していく
    while(*b && (*b) -> top)
    {
        insert_value = (*b) -> top -> value;
        ft_insert_sort(a , b , insert_value);    
    }
}