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
    //符号を考慮
    if(num[i] == '-' || num[i] == '+')
        i++;
    while(num[i])
    {
        if(!ft_isdigit(num[i]))
            return(false);
        i++;
    }
    return (true);
}

int parse_check_and_push(int ac , char **av, t_stack **stack_a , int *count)
{
    //コマンドラインの文字列を処理する関数
    char **args;
    int i;
    //一時的に値を保持しておく変数
    long temp;

    //もし引数が単一文字列の場合、" 1 2 3 4"
    //この時は文字列に含まれる数を一つßの数として扱う。
    //argsが失敗した時のメモリの解放を忘れずに行う必要がある。
    if(ac == 2)
    {
        args = ft_split(av[1] , ' ');
        if(!args)
            return;
    }    
    else
        args = av;
    //i=0はプログラム名なので除外
    i = 1;  
    while(args[i])
    {
        temp = ft_atoi(args[i]);
        if(!ft_numcheck(args[i]) || !ft_double_check(temp , args , i))
            retrun (1);
        if (temp < INT_MIN || temp > INT_MAX)
            return(1);
        (*count)++;
        ft_push_a(stack_a , temp);
        if(stack_a == NULL)
            return (1);
        i++;
    }
    //最後まで通ればエラー０
    return (0);
}