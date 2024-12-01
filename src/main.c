/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:23:39 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/01 20:26:46 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"
#include "stdio.h"

t_stack *ft_init_stack()
{
    //ヒープ領域にスタック構造体のメモリを確保
    t_stack *new_stack = malloc(sizeof(t_stack));
    if(new_stack == NULL)
        return (NULL);
    // 番兵ノードの先頭になる
    new_stack -> top = NULL;
    return (new_stack);
}

void print_stack_a(t_stack **stack_a)
{
    t_node *temp;
    t_node *first;

    temp = (*stack_a) ->top;
    first = temp;
    printf("%s\n" , "this is stack_a");
    printf("%d " , temp -> value);
    temp = temp -> next;
    while(temp != first)
    {
        printf("%d " , temp -> value);
        temp = temp -> next;
    }
    printf("\n");
}

void print_stack_b(t_stack **stack_b)
{
    t_node *temp;
    t_node *first;

    temp = (*stack_b) ->top;
    first = temp;
    printf("%s\n" , "this is stack_b");
    printf("%d " , temp -> value);
    temp = temp -> next;
    while(temp != first)
    {
        printf("%d " , temp -> value);
        temp = temp -> next;
    }
    printf("\n"); 
}

int main(int ac , char *av[])
{
    //ポインタ変数として宣言
    t_stack *stack_a;
    t_stack *stack_b;
    bool sorted_flag;
    int error_flag;
    int count;

    //stackの初期化
    stack_a = ft_init_stack();
    stack_b = ft_init_stack();
    if (stack_a == NULL || stack_b == NULL)
        return (0);
    //引数の長さを保持しておきたい
    count = 0;
    //errorフラグを立てておく。もし立ったら終了して忘れずfree関数に投げる
    error_flag = ft_parse_check_and_push(ac , av ,&stack_a , &count);
    if (error_flag == 1)
    {
        ft_putstr_fd("Error" , 1);
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (0);
    }
    sorted_flag = ft_isSorted(stack_a);
    if(sorted_flag)
    {
        free_stack(&stack_a);
        return (0);
    }
    //sortアルゴリズムを実装
    ft_sort_stack(&stack_a , &stack_b , count);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}