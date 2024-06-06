#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_node 
{
    int value;
    struct s_node *next;
    struct s_node *pre;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

void free_stack(t_stack **stack);
t_stack *init_stack(void);
int pase_check_and_push(int ac , char **av, t_stack **stack_a , int *count);
bool ft_numcheck(char *num);
bool ft_double_check(int temp , char **args , int i);

