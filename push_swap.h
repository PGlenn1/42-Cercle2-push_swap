#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft_42/libft.h"

typedef struct s_stack {
    int index;
    int value;
    struct s_stack *next;
} t_stack;

void	ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ps_lstnew(int value, int index);
t_stack	*ps_lstlast(t_stack *lst);

#endif