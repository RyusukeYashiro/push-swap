#include "../include/push_swap.h"

t_stack *init_stack(void)
{
    //ヒープ領域にスタック構造体のメモリを確保
    t_stack *new_stack = malloc(sizeof(t_stack));
    if(new_stack == NULL)
        return (NULL);
    // 番兵ノードの先頭になる
    new_stack -> top = NULL;
    return (new_stack);
}


int main(int ac , char *av[])
{
    //ポインタ変数として宣言
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *command_result;
    int error_flag;
    int count;

    //stackの初期化
    stack_a = init_stack();
    stack_b = init_stack();
    if (stack_a == NULL || stack_b == NULL)
        return (1);
    //引数の長さを保持しておきたい
    count = 0;
    //errorフラグを立てておく。もし立ったら終了して忘れずfree関数に投げる
    error_flag = pase_check_and_push(ac , av ,&stack_a , &count);
    
    if (error_flag)
    {
        ft_putstr("Error\n");
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (1);
    }
    //sortアルゴリズムを実装
    ft_sort_stack(&stack_a , &stack_b , &command_result);
    //sortしたコマンドを出力する
    print_command(command_result);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}