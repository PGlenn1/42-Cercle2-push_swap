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

void	push_ab(t_stack *from, t_stack *to)
{
	t_elem	*last_from;

	printf("push AB\n");
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

	if (!stack)
		ft_error(PTR_ERROR);
	if (!stack->first || !stack->first->next || stack->size <= 3)
		printf(BAD_OPS);
	ab == A ? printf("sa\n") : printf("sb");
	tmp = stack->last->value;
	stack->last->value = stack->last->prev->value;
	stack->last->prev->value = tmp;
}

void	ss(t_root *root)
{
	if (!root->stack_a || !root->stack_b)
		ft_error(PTR_ERROR);
	if (!root->stack_a->first || !root->stack_a->first->next
		|| !root->stack_b->first || !root->stack_b->first->next)
	{
		printf(MORE_NODES);
		return ;
	}
	else
	{
		printf("ss\n");
		swap_ab(root->stack_a, A);
		swap_ab(root->stack_b, B);
	}
}

void	rotate(t_stack *stack)
{
	t_elem	*tmp;

	if (!stack || !stack->first)
		ft_error(PTR_ERROR);
	if (!stack->first->next || !stack->sec_last)
	{
		printf(MORE_NODES);
		return ;
	}
	tmp = stack->first;
	stack->first = stack->last;
	stack->first->next = tmp;
	if (stack->sec_last)
		stack->sec_last->next = NULL;
}

void	rotate_ab(t_root *root, stack_ab ab)
{
	t_stack	*stack;

	if (ab == A)
		stack = root->stack_a;
	else
		stack = root->stack_b;
	if (!stack)
	{
		printf(MORE_NODES);
		return ;
	}
	else
	{
		(ab == A ? printf("ra\n") : printf("rb\n"));
		rotate(stack);
		// update_stack_ptrs(stack->size, stack);
	}
	// root->ops++;
}

void	rr(t_root *root)
{
	if (!root->stack_a || !root->stack_b)
		ft_error(PTR_ERROR);
	if (!root->stack_a->first || !root->stack_a->first->next
		|| !root->stack_a->sec_last || !root->stack_b->first
		|| !root->stack_b->first->next || !root->stack_b->sec_last)
	{
		printf(MORE_NODES);
		return ;
	}
	else
	{
		printf("rr\n");
		rotate_ab(root, A);
		rotate_ab(root, B);
	}
}

void	rev_rotate(t_stack *stack)
{
	t_elem	*tmp;

	if (!stack->first)
		ft_error(UNWANTED_BEHAVIOR);
	tmp = stack->first->next;
	if (!stack->sec_last || !stack->first->next)
	{
		printf(MORE_NODES);
		return ;
	}
	else
	{
		stack->first->next = NULL;
		stack->last->next = stack->first;
		stack->first = tmp;
	}
}

void	rev_rotate_ab(t_root *root, stack_ab ab)
{
	t_stack	*stack;

	printf("REVERSE ROTATE\n");
	if (ab == A)
		stack = root->stack_a;
	else
		stack = root->stack_a;
	(ab == A ? printf("rra\n") : printf("rrb\n"));
	rev_rotate(stack);
	// update_stack_ptrs(stack->size, stack);
}

void	rrr(t_root *root)
{
	if (!root->stack_a->first)
		ft_error(PTR_ERROR);
	if (!root->stack_a->sec_last || !root->stack_a->first->next
		|| !root->stack_b->sec_last || !root->stack_b->first->next)
	{
		printf(MORE_NODES);
		return ;
	}
	else
	{
		printf("rrr\n");
		rev_rotate_ab(root, A);
		rev_rotate_ab(root, B);
	}
}