//stack_aを座標圧縮して適切なピボットを求めるための関数
//実装は２分探を用いる予定


#include "../include/push_swap.h"

void ft_swap(t_node **s1 , t_node **s2)
{
    t_node *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void ft__sort(t_node **array_copy , int left , int right)
{
    int pivot_index;
    int pivot;
    int i;
    int j;

    if(right - left <= 1)
        return;
    pivot_index = (left + right) / 2;
    pivot = array_copy[pivot_index] ->  value;
    //array_copyはt_node**型であり、t_node *型のポインタを要素とする配列
    //そのため[]演算子を使っている（t_node* の要素を取得している）はt_node *型になる
    //だから呼び出し元で要素を変えたいから"&"をつけてそのアドレスを習得して(t_node**)ポインタのポインタ
    //にしている。ややこしい
    ft_swap(&array_copy[left] , &array_copy[pivot_index]);
    i = left + 1;
    j = left + 1;
    while(j < right)
    {
        if(array_copy[j] < pivot)
        {
            ft_swap(&array_copy[i] , &array_copy[j]);
            i++;
        }
        j++;
    }
    ft_swap(&array_copy[left] , &array_copy[i - 1]);
    ft_sort(array_copy , left , i);
    ft_sort(array_copy , i , right);
}

void ft_binary_search(t_node **result , t_node **array_copy , int count)
{

}


void ft_compress(t_stack **a , t_node **array_copy , int count)
{
    t_node **result;
    int left;
    int right;

    left = 0;
    right = count;
    result = ft_pointer_buffer(a , count);
    ft_sort(array_copy , left , right);
    ft_binary_search(result, array_copy , count);




}