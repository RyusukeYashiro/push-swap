/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:20:17 by ryusukeyash       #+#    #+#             */
/*   Updated: 2024/12/01 20:21:12 by ryusukeyash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
typedef struct s_node
{
    int value;
    struct s_node *next;
    struct s_node *pre;
} t_node ;

typedef struct s_stack
{
    t_node *top;
} t_stack;

int	main(int argc, char **argv);
void pa(t_stack **stack_a ,t_stack **stack_b);
void pb(t_stack **stack_a , t_stack **stack_b);
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a , t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a , t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a , t_stack **stack_b);

t_stack *ft_init_stack();
void ft_sort_stack(t_stack **a , t_stack **b , int count);
int ft_find_index(t_stack **stack, int *array , int len);
int ft_digit(int num);
void ft_radix_sort(t_stack **a , t_stack **b , int len);
void ft_sort_min_b(t_stack **stack_b, int count);
void ft_sort_min_a(t_stack **stack_a, int count);
void ft_sort_three_a(t_stack **stack_a);
void ft_sort_three_b(t_stack **stack_a);
void ft_rotation_sort(t_stack **stack_a);
void ft_sort_check(int pos, int pos_len , t_stack **stack_a , t_stack **stack_b);
void ft_insert_sort(t_stack **stack_a , t_stack **stack_b , int num);
void ft_sort_mid(t_stack **a  , t_stack **b , int count);

//utils
void free_stack(t_stack **stack);
int count_stack_len_a(t_stack **stack_a);
int count_stack_len_b(t_stack **stack_b);
void ft_push_a(t_stack **stack_a , int  num);
int stack_a_min(t_stack **stack_a);
int stack_a_max(t_stack **stack_a);
bool ft_double_check(int temp , char **args , int current_i);
bool ft_numcheck(char *num);
int ft_parse_check_and_push(int ac , char **av, t_stack **stack_a , int *count);
void print_stack_a(t_stack **stack_a);
void print_stack_b(t_stack **stack_b);
bool ft_isSorted(t_stack *a);

#endif