#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	if (!from || !to)
		ft_error(PTR_ERROR);
	if (!from->first)
	{
		printf(BAD_OPS);
		return ;
	}
	if (!to->first)
		to->first = from->last;
	else
		to->last->next = from->last;
	if (from->sec_last)
		from->sec_last->next = NULL;
	else if (from->first->next)
		from->first->next = NULL;
	else
		from->first = NULL;
}


void	push_ab(t_root *root, stack_ab ab)
{
	t_stack *from;
	t_stack *to;

	if (ab == A)
	{
		from = root->stack_b;
		to = root->stack_a;
	}
	else
	{	
		from = root->stack_a;
		to = root->stack_b;
	}
	ab == A ? printf("pa\n") : printf("pb\n");
	from->size--;
	to->size++;
	push(from, to);
	update_stack_ptrs(root);
}

void	swap(t_root *root, t_stack *stack)
{
	if (!stack->first || !stack->first->next)
	 	return ;
	if (stack->sec_last)
	{
		if (stack->thi_last)
			stack->thi_last->next = stack->last;
		stack->last->next = stack->sec_last;
		stack->sec_last->next = NULL;
	}
	else
	{
		stack->last->next = stack->first;
		stack->first->next = NULL;
		stack->first = stack->last;
	}
	update_stack_ptrs(root);
}

void	swap_ab(t_root *root, stack_ab ab)	
{
	t_stack *stack;

	if (ab == A)
		stack = root->stack_a;
	else
		stack = root->stack_b;
	if (!stack)
		ft_error(PTR_ERROR);
	if (!stack->first || !stack->first->next)
	{
		printf(BAD_OPS);
		return ;
	}
	(ab == A ? printf("sa\n") : printf("sb\n"));
	swap(root, stack);
}

void	ss(t_root *root)
{
	if (!root->stack_a || !root->stack_b)
		ft_error(PTR_ERROR);
	 if (!root->stack_a->first || !root->stack_a->first->next || !root->stack_b->first || !root->stack_b->first->next)
	{
		printf(BAD_OPS);
		return ;
	}
	else
	{
		printf("ss\n");
		swap_ab(root, A);
		swap_ab(root, B);
	}
}

void	rotate(t_stack *stack)
{
	t_elem *tmp;

	if (!stack || !stack->first)
		ft_error(PTR_ERROR);
	if (!stack->first->next || !stack->sec_last)
	{
		printf(BAD_OPS);
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

	t_stack *stack;
	if (ab == A)
		stack = root->stack_a;	
	else
		stack = root->stack_b;	
	if (!stack)	
	{
		printf(BAD_OPS);
		return;
	}
	else
	{
		(ab == A ? printf("ra\n") : printf("rb\n"));
		rotate(stack);
	}
	update_stack_ptrs(root);
}


void	rr(t_root *root)
{
	if (!root->stack_a || !root->stack_b)
		ft_error(PTR_ERROR);
	if (!root->stack_a->first || !root->stack_a->first->next || !root->stack_a->sec_last
		|| !root->stack_b->first || !root->stack_b->first->next || !root->stack_b->sec_last)
	{
		printf(BAD_OPS);
		return ;
	}
	else
	{
		printf("rr\n");
		rotate_ab(root, A);
		rotate_ab(root, B);
	}
}


void rev_rotate(t_stack *stack)
{
	t_elem *tmp;

	if (!stack->first) 
		ft_error(UNWANTED_BEHAVIOR);
	tmp = stack->first->next;
	if (!stack->sec_last || !stack->first->next)
	{
		printf(BAD_OPS);
		return ;
	}
	else
	{
		stack->first->next = NULL;
		stack->last->next = stack->first;
		stack->first = tmp;
	}
}

void rev_rotate_ab(t_root *root, stack_ab ab)
{
	t_stack *stack;
	printf("REVERSE ROTATE\n");
	if (ab == A)
		stack = root->stack_a;
	else
		stack = root->stack_a;
	(ab == A ? printf("rra\n") : printf("rrb\n"));
	rev_rotate(stack);
	update_stack_ptrs(root);
}

void	rrr(t_root *root)
{
	if (!root->stack_a->first)
	 	ft_error(PTR_ERROR);
	if (!root->stack_a->sec_last || !root->stack_a->first->next || !root->stack_b->sec_last || !root->stack_b->first->next)
	{
		printf(BAD_OPS);
		return ;
	}
	else
	{
		printf("rrr\n");
		rev_rotate_ab(root, A);
		rev_rotate_ab(root, B);
	}
}