#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
    struct s_node *pre;
} t_node ;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

void free_stack(t_stack **stack);
int parse_check_and_push(int ac , char **av, t_stack **stack_a , int *count);
void ft_push_a(t_stack **stack_a , int  num);
bool ft_double_check(int temp , char **args , int i);
bool ft_numcheck(char *num);


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

// void free_stack(t_stack **stack);
// t_stack *init_stack(void);
// int pase_check_and_push(int ac , char **av, t_stack **stack_a , int *count);
// bool ft_numcheck(char *num);
// bool ft_double_check(int temp , char **args , int i);

