#include "../include/push_swap.h"

t_stack *init_stack(void)
{
    t_stack *new_stack = malloc(sizeof(t_stack));
    if(new_stack == NULL)
        return (NULL);
    new_stack -> top = NULL;
    return (new_stack);
}

int main(int ac , char *av[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *hold;
    int error_flag;
    int count;

    stack_a = init_stack();
    stack_b = init_stack();
    hold = NULL;
    count = 0;
    error_flag = pase_check_and_push(ac , av , &stack_a , &count);
    if(error_flag)
    {
        ft_putstr("Eroor\n");
        free_stack(&stack_a);
        free_stack(&stack_b);
        return (1);
    }
    sort_stack(&stack_a , &stack_b , &hold , count);
    print_and_free(&hold);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}