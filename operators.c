#include "push_swap.h"

void	push(t_stack *to, t_elem *last_from)
{
	if (to->size >= 1)
	{
		if (to->size == 1)
		{
			to->first->next = last_from;
			last_from->prev = to->first;
		}
		else
		{
			to->last->next = last_from;
			last_from->prev = to->last;
		}
		to->last = last_from;
	}
	else
	{
		to->first = last_from;
		to->first->prev = NULL;
		to->last = to->first;
	}
}

void	push_ab(t_stack *from, t_stack *to, stack_ab ab)
{
	t_elem	*last_from;

	ab == A ? printf("pa\n") : printf("pb\n");
	last_from = from->last;
	if (!from || !to)
		ft_error(PTR_ERROR);
	if (!from->first)
	{
		printf(BAD_OPS);
		return ;
	}
	if (from->size == 1)
		from->first = from->last = NULL;
	else if (from->size > 1)
	{
		from->last = from->last->prev;
		from->last->next = NULL;
	}
	push(to, last_from);
	from->size--;
	to->size++;
}

void	swap_ab(t_stack *stack, stack_ab ab)
{
	int	tmp;

	ab == A ? printf("sa\n") : printf("sb");
	if (!stack)
		ft_error(PTR_ERROR);
	if (!stack->first || !stack->first->next || stack->size <= 1)
		printf(BAD_OPS);
	tmp = stack->last->value;
	stack->last->value = stack->last->prev->value;
	stack->last->prev->value = tmp;
}

void	ss(t_root *root)
{
	printf("ss\n");
	if (!root->stack_a || !root->stack_b)
		ft_error(PTR_ERROR);
	if (root->stack_a->size <= 3 || root->stack_b->size <= 3)
	{
		printf(MORE_NODES);
		return ;
	}
	swap_ab(root->stack_a, A);
	swap_ab(root->stack_b, B);
}

void	rotate_ab(t_stack *stack, stack_ab ab)
{
	t_elem	*second;
	t_elem	*sec_last;

	ab == A ? printf("ra\n") : printf("rb\n");
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

void	rr(t_root *root)
{
	printf("rr\n");
	rotate_ab(root->stack_a, A);
	rotate_ab(root->stack_b, B);
}

void	rev_rotate_ab(t_stack *stack, stack_ab ab)
{
	t_elem	*second;

	ab == A ? printf("rra\n") : printf("rrb\n");
	if (!stack)
		ft_error(PTR_ERROR);
	if (stack->size <= 1)
	{
		printf(MORE_NODES);
		return ;
	}
	second = stack->first->next;
	stack->last->next = stack->first;
	stack->first->prev = stack->last;
	stack->first->next = NULL;
	stack->last = stack->first;
	stack->first = second;
	stack->first->prev = NULL;
}

void	rrr(t_root *root)
{
	printf("rrr\n");
	rev_rotate_ab(root->stack_a, A);
	rev_rotate_ab(root->stack_b, B);
}