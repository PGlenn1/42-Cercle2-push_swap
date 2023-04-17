#include "push_swap.h"

void	push(t_stack *to, t_elem *first_from)
{
	if (to->size == 0)
	{
		first_from->next = NULL;
		to->last = first_from;
	}
	else
	{
		to->first->prev = first_from;
		first_from->next = to->first;
	}
	to->first = first_from;
}

void	push_ab(t_stack *from, t_stack *to)
{
	t_elem	*first_from;

	if (!from || !to)
		ft_error(PTR_ERROR);
	if (!from->first)
	{
		printf(BAD_OPS);
		return ;
	}
	first_from = from->first;
	if (from->size == 1)
		from->first = from->last = NULL;
	else if (from->size > 1)
	{
		from->first = from->first->next;
		from->first->prev = NULL;
	}
	push(to, first_from);
	from->size--;
	to->size++;
}

void	swap_ab(t_stack *stack)
{
	int	val_tmp;
	int	ind_tmp;

	if (!stack)
		ft_error(PTR_ERROR);
	if (!stack->first || !stack->first->next || stack->size <= 1)
	{
		printf(BAD_OPS);
		return ;
	}
	val_tmp = stack->first->value;
	stack->first->value = stack->first->next->value;
	stack->first->next->value = val_tmp;

	ind_tmp = stack->first->index;
	stack->first->index = stack->first->next->index;
	stack->first->next->index = ind_tmp;
}

void	ss(t_root *root)
{
	if (!root->stack_a || !root->stack_b)
		ft_error(PTR_ERROR);
	if (root->stack_a->size <= 3 || root->stack_b->size <= 3)
	{
		printf(MORE_NODES);
		return ;
	}
	swap_ab(root->stack_a);
	swap_ab(root->stack_b);
}

void	rotate_ab(t_stack *stack)
{
	if (!stack)
		ft_error(PTR_ERROR);
	if (stack->size <= 1)
	{
		printf(MORE_NODES);
		return ;
	}
	stack->first->next->prev = NULL;
	stack->last->next = stack->first;
	stack->first->prev = stack->last;
	stack->last = stack->first;
	stack->first = stack->first->next;
	stack->last->next = NULL;
}

void	rr(t_root *root)
{
	rotate_ab(root->stack_a);
	rotate_ab(root->stack_b);
}

void	rev_rotate_ab(t_stack *stack)
{
	t_elem	*second;
	t_elem	*sec_last;

	if (!stack)
		ft_error(PTR_ERROR);
	if (stack->size <= 1)
	{
		printf(MORE_NODES);
		return ;
	}
	sec_last = stack->last->prev;
	second = stack->first;
	stack->first->prev = stack->last;
	stack->first = stack->last;
	stack->first->prev = NULL;
	stack->first->next = second;
	stack->last = sec_last;
	sec_last->next = NULL;
}

void	rrr(t_root *root)
{
	rev_rotate_ab(root->stack_a);
	rev_rotate_ab(root->stack_b);
}