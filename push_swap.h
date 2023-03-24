#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_42/libft.h"
# include <stdbool.h>

#define BAD_OPS "NOT ENOUGH NODES\n"


typedef enum
{
	NAN,
	ALREADY_SORTED,
	OVERFLOW,
	DOUBLE,
	PTR_ERROR,
	MALLOC_FAIL,
	UNWANTED_BEHAVIOR,
	DEBUG,
} errors;

typedef enum
{
	A,
	B,
} stack_ab;

typedef struct s_stack
{
	struct s_elem	*first;
	struct s_elem	*last;
	struct s_elem	*sec_last;
	struct s_elem 	*thi_last;
	int	size;
} t_stack;

typedef struct s_elem
{
	int				value;
	struct s_elem	*next;
}					t_elem;

typedef struct s_root
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	struct s_data	*data;
}					t_root;


t_root				*init_root(char **input);
void				print_sort_opt(int first, int sec_last, int last);
void				update_stack_ptrs(t_root *root);
int					get_stack_size(t_stack *stack);
void				ps_lstadd_back(t_elem **lst, t_elem *new);
t_elem				*get_second_last(t_stack *stack);
t_elem				*get_third_last(t_stack *stack);
t_elem				*ps_lstnew(int value);
t_elem				*ps_lstlast(t_elem *lst);
t_elem				*ps_lstprev(t_elem *stack);
void				print_both(t_root *root);
void				swap_ab(t_root *root, stack_ab ab);
void				ss(t_root *root);
void				push_ab(t_root *root, stack_ab ab);
void				rotate_ab(t_root *root, stack_ab ab);
void 				rev_rotate_ab(t_root *root, stack_ab ab);
void				rrr(t_root *root);
void				rr(t_root *root);
void				ft_error(errors error);

#endif