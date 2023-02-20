#include "push_swap.h"

t_stack	*ps_lstprev(t_stack *stack)
{
	t_stack	*probe;

	if (!stack)
		return (NULL);
	printf("LSTPREV\n");
	probe = stack;
	while ((probe)->next)
	{
		if (probe->next && (probe->next->next) == NULL)
		{
			printf("probe->index:%d\n", probe->index);
			printf("probe->value:%d\n", probe->value);
			return (probe->next);
		}
		printf("PROUT\n");
		probe = probe->next;
	}
	return (probe);
}

t_stack	*ps_lstnew(int value, int index)
{
	struct s_stack	*ptr;

	ptr = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!ptr)
		return (NULL);
	ptr->index = index;
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	struct s_stack *last;

	// printf("\nADDBACK\n");
	// printf("new:%p\n", new);
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
	// printf("last:%p\n", last);
}