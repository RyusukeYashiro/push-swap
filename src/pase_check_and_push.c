#include "../include/push_swap.h"

bool ft_double_check(int temp , char **args , int i)
{
    int num;
    
    num = ft_atoi(args[i++]);
    while(args[i])
    {
        if(ft_atoi(args[i]) == temp)
            return(false);
        i++;
    }
    return (true);
}

bool ft_numcheck(char *num) 
{
    int i;

    i = 0;
    while(num[i])
    {
        if(!ft_isdigit(num[i]))
            return(false);
        i++;
    }
    return (true);
}

int pase_check_and_push(int ac , char **av, t_stack **stack_a , int *count)
{
    //コマンドラインの文字列を処理する関数
    char **args;
    int i;
    //一時的に値を保持しておく変数
    long temp;

    i = 0;  
    while(args[i])
    {
        temp = ft_atoi(args[i]);
        if(!ft_numcheck(args[i]))
            retrun (1);
        if(ft_double_check(temp , args , i))
            retrun(1);
        if (temp < -2147483648 || temp > 2147483647)
            return(1);
        count++;
        ft_push_a(&stack_a , temp);
        i++;
    }
    retrun(0);
}