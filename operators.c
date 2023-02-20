#include "push_swap.h"

void	swap_a(t_root *root)
{
	t_stack	*last;
	t_stack	*prev;
	int		tmp_index;

	printf("STACK A\n");
	last = ps_lstlast(root->stack_a);
	if (last->index < 1)
		return ;
	prev = ps_lstprev(root->stack_a);
	printf("prev->value:%d\n", prev->value);
	printf("prev->index:%d\n", prev->index);
	tmp_index = last->index;
	printf("tmp_index:%d\n", tmp_index);
	printf("last->index:%d\n", last->index);
	printf("prev->index:%d\n", prev->index);
	last->index = prev->index;
	prev->index = tmp_index;
}

void	swap_b(t_root *root)
{
	t_stack *last;
	t_stack *prev;
	int tmp_index;

	last = ps_lstlast(root->stack_a);
	if (last->index < 1)
		return ;
	prev = ps_lstprev(root->stack_a);
	tmp_index = last->index;
	last->index = prev->index;
	prev->index = tmp_index;
}