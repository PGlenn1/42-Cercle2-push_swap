
#include "../includes/push_swap.h"

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
