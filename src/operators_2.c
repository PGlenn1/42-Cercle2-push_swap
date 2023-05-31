/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glpiriou <glpiriou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:20:41 by glpiriou          #+#    #+#             */
/*   Updated: 2023/05/31 16:21:03 by glpiriou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_ab(t_stack *stack, int rr)
{
	stack->first->next->prev = NULL;
	stack->last->next = stack->first;
	stack->first->prev = stack->last;
	stack->last = stack->first;
	stack->first = stack->first->next;
	stack->last->next = NULL;
	if (rr == 1)
		return ;
	write(1, "r", 1);
	write(1, &stack->ab, 1);
	write(1, "\n", 1);
}

void	rr(t_root *root)
{
	rotate_ab(root->stack_a, 1);
	rotate_ab(root->stack_b, 1);
	write(1, "rr\n", 3);
}

void	rev_rotate_ab(t_stack *stack, int rrr)
{
	t_elem	*sec_last;

	sec_last = stack->last->prev;
	stack->last->next = stack->first;
	stack->first->prev = stack->last;
	stack->first = stack->last;
	stack->first->prev = NULL;
	stack->last = sec_last;
	sec_last->next = NULL;
	if (rrr == 1)
		return ;
	write(1, "rr", 2);
	write(1, &stack->ab, 1);
	write(1, "\n", 1);
}

void	rrr(t_root *root)
{
	rev_rotate_ab(root->stack_a, 1);
	rev_rotate_ab(root->stack_b, 1);
	write(1, "rrr\n", 4);
}
