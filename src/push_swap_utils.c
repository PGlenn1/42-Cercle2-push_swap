#include "../includes/push_swap.h"

order_type	stack_is_sorted(t_stack *stack)
{
	t_elem	*probe;

	probe = stack->first;
	while (probe && probe->next)
	{
		if (probe->index + 1 != probe->next->index)
			return (NOT_SORTED);
		probe = probe->next;
	}
	return (INCREASING);
}

int	final_is_sorted(t_root *root)
{
	if (stack_is_sorted(root->stack_a) == INCREASING
		&& root->stack_a->size == root->input_size)
		return (1);
	else
		return (0);
}

t_elem	*ps_lstnew(int value)
{
	struct s_elem	*ptr;

	ptr = (struct s_elem *)malloc(sizeof(struct s_elem));
	if (!ptr)
		return (NULL);
	ptr->index = 0;
	ptr->value = value;
	ptr->prev = NULL;
	ptr->next = NULL;
	return (ptr);
}

t_elem	*ps_lstlast(t_elem *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_back(t_elem **lst, t_elem *new)
{
	struct s_elem *last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	new->prev = last;
	last->next = new;
}