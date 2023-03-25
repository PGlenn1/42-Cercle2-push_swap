#include "push_swap.h"



void	push(t_stack *from, t_stack *to)
{
	if (!from || !to)
		ft_error(PTR_ERROR);
	if (from->size == 0)
	{
		printf(MORE_NODES);
		return ;
	}
	if (to->size == 0)
	{
		to->first = from->last;	
	}
	else if (to->size > 0)
	{
		to->last = from->last;	
		to->sec_last->next = to->last;
		to->last->prev = to->sec_last;
	}
	if (from->size == 1)
	{
		from->first = NULL;
	}
	else
	{
		from->sec_last->next = NULL;
	}
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
	print_both(root);
	from->size--;
	to->size++;
	push(from, to);
	update_stack_ptrs(from->size, from);
	update_stack_ptrs(to->size, to);
	root->ops++;
}

void	swap(t_stack *stack)
{
	if (!stack->first || !stack->first->next)
	{
		printf(MORE_NODES);
	 	return ;
	}
	if (stack->sec_last)
	{
		if (stack->thi_last)
			stack->thi_last->next = stack->last;
		else 
			stack->first->next = stack->last;
		stack->last->next = stack->sec_last;
		stack->sec_last->next = NULL;
	}
	else
	{
		stack->last->next = stack->first;
		stack->first->next = NULL;
		stack->first = stack->last;
	}
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
		printf(MORE_NODES);
		return ;
	}
	(ab == A ? printf("sa\n") : printf("sb\n"));
	root->ops++;
	swap(stack);
	update_stack_ptrs(stack->size, stack);
}

void	ss(t_root *root)
{
	if (!root->stack_a || !root->stack_b)
		ft_error(PTR_ERROR);
	 if (!root->stack_a->first || !root->stack_a->first->next || !root->stack_b->first || !root->stack_b->first->next)
	{
		printf(MORE_NODES);
		return ;
	}
	else
	{
		printf("ss\n");
		swap_ab(root, A);
		swap_ab(root, B);
		root->ops += 2;
	}
}

void	rotate(t_stack *stack)
{
	t_elem *tmp;

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

	t_stack *stack;
	if (ab == A)
		stack = root->stack_a;	
	else
		stack = root->stack_b;	
	if (!stack)	
	{
		printf(MORE_NODES);
		return;
	}
	else
	{
		(ab == A ? printf("ra\n") : printf("rb\n"));
		rotate(stack);
		update_stack_ptrs(stack->size, stack);
	}
	root->ops++;
}


void	rr(t_root *root)
{
	if (!root->stack_a || !root->stack_b)
		ft_error(PTR_ERROR);
	if (!root->stack_a->first || !root->stack_a->first->next || !root->stack_a->sec_last
		|| !root->stack_b->first || !root->stack_b->first->next || !root->stack_b->sec_last)
	{
		printf(MORE_NODES);
		return ;
	}
	else
	{
		printf("rr\n");
		rotate_ab(root, A);
		rotate_ab(root, B);
		root->ops += 2;
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
	root->ops++;
	update_stack_ptrs(stack->size, stack);
}

void	rrr(t_root *root)
{
	if (!root->stack_a->first)
	 	ft_error(PTR_ERROR);
	if (!root->stack_a->sec_last || !root->stack_a->first->next || !root->stack_b->sec_last || !root->stack_b->first->next)
	{
		printf(MORE_NODES);
		return ;
	}
	else
	{
		printf("rrr\n");
		rev_rotate_ab(root, A);
		rev_rotate_ab(root, B);
		root->ops += 2;
	}
}