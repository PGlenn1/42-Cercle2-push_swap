#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_42/libft.h"
# include <stdbool.h>

typedef struct s_root
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	struct s_data	*data;
}					t_root;

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				ops;

}					t_data;

void				ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ps_lstnew(int value);
t_stack				*ps_lstlast(t_stack *lst);
t_stack				*ps_lstprev(t_stack *stack);
void				print_both(t_root *root);
void				swap_a(t_stack *stack);
void				swap_b(t_stack *stack);
void				ss(t_root *root);
void				push_a(t_root *root);
void				push_b(t_root *root);
void				rotate_a(t_root *root);
void				rotate_b(t_root *root);
void				rrr(t_root *root);
void				rr(t_root *root);
void				reverse_rotate_a(t_root *root);
void				reverse_rotate_b(t_root *root);
void				print_node(t_stack *node);
void				ft_error(const char *str);

#endif