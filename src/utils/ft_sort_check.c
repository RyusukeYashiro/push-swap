#include "../../include/push_swap.h"

bool ft_isSorted(t_stack *a)
{
    t_node *temp;
    temp = a -> top;

    while(1)
    {
        if(temp -> value > temp -> next -> value){
            return (false);
        }
        temp = temp -> next;
        if(temp -> next == a -> top)
            break;
    }
    return (true);
}