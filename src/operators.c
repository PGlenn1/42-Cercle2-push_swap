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
	write(1, "p", 1);
	write(1, &to->ab, 1);
	write(1, "\n", 1);
}

void	swap_ab(t_stack *stack)
{
	int	ind_tmp;

	ind_tmp = stack->first->index;
	stack->first->index = stack->first->next->index;
	stack->first->next->index = ind_tmp;
	write(1, "s", 1);
	write(1, &stack->ab, 1);
	write(1, "\n", 1);
}

void	ss(t_root *root)
{
	swap_ab(root->stack_a);
	swap_ab(root->stack_b);
	write(1, "ss\n", 3);
}

void	rotate_ab(t_stack *stack)
{
	stack->first->next->prev = NULL;
	stack->last->next = stack->first;
	stack->first->prev = stack->last;
	stack->last = stack->first;
	stack->first = stack->first->next;
	stack->last->next = NULL;
	write(1, "r", 1);
	write(1, &stack->ab, 1);
	write(1, "\n", 1);
}

void	rr(t_root *root)
{
	rotate_ab(root->stack_a);
	rotate_ab(root->stack_b);
	write(1, "rr\n", 3);
}

void	rev_rotate_ab(t_stack *stack)
{
	t_elem	*sec_last;

	sec_last = stack->last->prev;
	stack->last->next = stack->first;
	stack->first->prev = stack->last;
	stack->first = stack->last;
	stack->first->prev = NULL;
	stack->last = sec_last;
	sec_last->next = NULL;
	write(1, "rr", 2);
	write(1, &stack->ab, 1);
	write(1, "\n", 1);
}

void	rrr(t_root *root)
{
	rev_rotate_ab(root->stack_a);
	rev_rotate_ab(root->stack_b);
	write(1, "rrr\n", 4);
}