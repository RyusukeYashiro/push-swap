#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

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
