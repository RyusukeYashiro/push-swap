/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:58 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/11/12 17:23:03 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//ヒープ領域のアドレスを持つポインタ変数であるstack_aのアドレスを持つポインタ（ダブルポインタ）がstack
void free_stack(t_stack **stack)
{
    t_node *temp;
    t_node *first;
    t_node *next;
    //そもそもstack自体がないかstack構造体自体が存在しない場合
    if(stack == NULL || *stack == NULL)
        return;
    //t_stack構造体の中のtopメンバにアクセス
    temp = (*stack) -> top;
    //もしstack構造体が一つだけなら
    if(temp -> next == temp)
    {
        free(temp);
        //stackはスタック領域にあるポインタ変数のアドレスなので*stackでヒープ領域にあるものを指す
        free(*stack);
        *stack == NULL;
        return;
    }
    first = temp;
    while(temp -> next != first)
    {
        next = temp -> next;
        free(temp);
        temp = next;
    }
    free(temp);
    free(*stack);
}