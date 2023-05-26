#include "../includes/push_swap.h"

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

void	swap_ab(t_stack *stack, int ss)
{
	int	ind_tmp;

	ind_tmp = stack->first->index;
	stack->first->index = stack->first->next->index;
	stack->first->next->index = ind_tmp;
	if (ss == 1)
		return ;
	write(1, "s", 1);
	write(1, &stack->ab, 1);
	write(1, "\n", 1);
}

void	ss(t_root *root)
{
	swap_ab(root->stack_a, 1);
	swap_ab(root->stack_b, 1);
	write(1, "ss\n", 3);
}
