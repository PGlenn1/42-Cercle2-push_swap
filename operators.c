#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list *node_tmp;
	t_list *last;
	t_list *prev;
	int index_tmp;
	int value_tmp;

	last = ps_lstlast(stack);
	if (last.index < 1)
		return ;
	prev = ps_lstprev()
}