#include "../include/push_swap.h"

//連結リストバージョン（もしかしたら使わないかも）
t_stack *deepCopy(t_stack *src , t_stack **copy_a)
{
    t_node *temp;
    t_node *newNode;
    t_node *copy_temp;

    if(src == NULL || src -> top == NULL)
        return (NULL);
    //別の関数でcopy_aのノードはつくられてあるからここでは
    //最初のノードの設定をしている。
    (*copy_a) -> top -> value = src -> top -> value;
    (*copy_a) -> top -> next = (*copy_a) -> top;
    (*copy_a) -> top -> pre = (*copy_a) -> top;
    //上記により先に進めているため、nextになる。
    temp = src -> top -> next;
    copy_temp = (*copy_a) -> top;
    while(temp != src -> top)
    {
        newNode = malloc(sizeof(t_node));
        if(!newNode)
            return(free_stack(copy_a) , NULL);
        //新しいノードの値にvalueの値をコピーしておく。
        newNode -> value = temp -> value;
        //newNodeのnext,preの設定
        newNode -> next = (*copy_a) -> top;
        newNode -> pre = copy_temp;
        //現在の場所を保存しているcopy_tempのnext,preの設定
        copy_temp -> next = newNode;
        (*copy_a) -> top -> pre = newNode;
        //最後のノードを更新
        copy_temp = newNode;
        temp = temp -> next;
    }
    retrun(*copy_a);
}

ft_pointer_array(t_stack *src , t_node ** array , int count)
{
    if(src == NULL || src -> top == NULL)
        return ;
    
}

void sort_algo(t_stack **a , t_stack **b , t_stack **hold , int count)
{
    char *array;
    t_node *copy_a;
    int pivot;

    //t_stack_aをランダムアクセスできる配列へと変換する関数
    ft_pointer_array(a , &array , count);
    //copy_a = init_stack();
    //deepCopy(a , &copy_a);
    pivot = 0;
    if(count <= 3)
    {

    }
    else if(count <= 6)
    {

    }
    else if(count >= 7)
    {
        ft_compress(&copy_a , count);
        pivot = ft_search_pivot(copy_a,count);
        ft_quick_sort(&a , &b , &hold , pivot);
    }

}
