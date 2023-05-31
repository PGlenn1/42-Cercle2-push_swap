/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:42:16 by glpiriou          #+#    #+#             */
/*   Updated: 2023/05/31 16:46:11 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft_42/libft.h"
# include <stdbool.h>

typedef enum op_call
{
	NOT_SET,
	SWAP,
	PUSH,
	ROT,
	REV_ROT,
}					t_op_call;

typedef enum order_type
{
	NOT_SORTED,
	INCREASING,
}					t_order_type;

typedef struct s_stack
{
	struct s_elem	*first;
	struct s_elem	*last;
	int				size;
	char			ab;
	t_op_call		operator;
	t_order_type	order;
}					t_stack;

typedef struct s_elem
{
	int				value;
	int				index;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct s_limits
{
	int				segment_size;
	int				limit_a;
	int				limit_b;
	int				limit_c;
	int				limit_d;
	int				median_a;
	int				median_b;
	int				median_c;
	int				median_d;
}					t_limits;

typedef struct s_root
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	struct s_limits	*limits;
	int				input_size;
}					t_root;

t_root				*init_root(char **input);
t_elem				*ps_lstnew(int value);
t_elem				*ps_lstlast(t_elem *lst);
void				ps_lstadd_back(t_elem **lst, t_elem *new);
int					check_input(char **input);
int					pre_sort(t_stack *stack);
t_order_type		stack_is_sorted(t_stack *stack);
int					final_is_sorted(t_root *root);
void				sort_stacks(t_root *root);
void				sort_large_numbers(t_root *root);
void				sort_three(t_root *root, t_stack *stack);
void				sort_three_ops(t_stack *stack, int first, int second,
						int third);
t_op_call			rev_or_rot(t_stack *stack, int target_index, int limit);
void				call_combined_ops(t_root *root);
void				swap_ab(t_stack *stack, int ss);
void				ss(t_root *root);
void				push_ab(t_stack *from, t_stack *to);
void				rotate_ab(t_stack *stack, int rr);
void				rev_rotate_ab(t_stack *stack, int rrr);
void				rrr(t_root *root);
void				rr(t_root *root);
void				ft_free_all(t_root *root, int error);

#endif