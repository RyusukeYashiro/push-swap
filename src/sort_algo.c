#include "../include/push_swap.h"

//連結リストバージョン（もしかしたら使わないかも）
// t_stack *deepCopy(t_stack *src , t_stack **copy_a)
// {
//     t_node *temp;
//     t_node *newNode;
//     t_node *copy_temp;

//     if(src == NULL || src -> top == NULL)
//         return (NULL);
//     別の関数でcopy_aのノードはつくられてあるからここでは
//     最初のノードの設定をしている。
//     (*copy_a) -> top -> value = src -> top -> value;
//     (*copy_a) -> top -> next = (*copy_a) -> top;
//     (*copy_a) -> top -> pre = (*copy_a) -> top;
//     上記により先に進めているため、nextになる。
//     temp = src -> top -> next;
//     copy_temp = (*copy_a) -> top;
//     while(temp != src -> top)
//     {
//         newNode = malloc(sizeof(t_node));
//         if(!newNode)
//             return(free_stack(*copy_a) , NULL);
//         新しいノードの値にvalueの値をコピーしておく。
//         newNode -> value = temp -> value;
//         newNodeのnext,preの設定
//         newNode -> next = (*copy_a) -> top;
//         newNode -> pre = copy_temp;
//         現在の場所を保存しているcopy_tempのnext,preの設定
//         copy_temp -> next = newNode;
//         (*copy_a) -> top -> pre = newNode;
//         最後のノードを更新
//         copy_temp = newNode;
//         temp = temp -> next;
//     }
//     retrun(*copy_a);
// }

//ランダムアクセスを可能にするための関数
t_node **ft_pointer_buffer(t_stack *src , int count)
{
    t_node **buffer;
    t_node *temp;
    t_node *first;
    int i;

    if(src == NULL || src -> top == NULL)
        return ;
    buffer = malloc(count * sizeof(t_node*));
    if(buffer == NULL)
        return NULL;
    temp = src -> top;
    first = src -> top;
    i = 0;
    while(i < count)
    {
        buffer[i] = temp;
        temp = temp -> next;
        if(temp == first)
            break;
        i++;
    } 
    return (buffer);
}

void sort_algo(t_stack **a , t_stack **b , t_stack **hold , int count)
{
    // t_node **array;
    // t_node **array_copy;
    // //t_stack_aをランダムアクセスできる配列へと変換する関数
    // array = ft_pointer_buffer(a , count);
    // array_copy = ft_pointer_buffer(a , count);
    // //copy_a = init_stack();
    // //deepCopy(a , &copy_a);
    // if(count <= 6)
    // {
    //     ft_sort_min(a , b, array , count);
    // }
    // else if(count >= 7)
    // {
    //     array = ft_compress(a,array_copy, count);
    //     ft_sort_long(array , a , b , hold);
    // }
    

}
