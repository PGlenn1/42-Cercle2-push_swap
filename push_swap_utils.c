#include "push_swap.h"

t_elem	*get_third_last(t_elem *stack)
{
	t_elem *probe;

	if (!stack || !stack->next || !stack->next->next)
		return (NULL);
	probe = stack;
	while (probe->next->next->next)
	{
		probe = probe->next;
	}
	return (probe);
}

void	update_stack_ptrs(t_root *root)
{
		root->stack_a->last = ps_lstlast(root->stack_a->first);
		// printf(" LAST A:%p\n", root->stack_a->last);
		root->stack_a->sec_last = get_second_last(root->stack_a->first);
		// printf("SC LAST A:%p\n", root->stack_a->sec_last);
		root->stack_a->thi_last = get_third_last(root->stack_a->first);

		root->stack_b->last = ps_lstlast(root->stack_b->first);
		// printf(" LAST B:%p\n", root->stack_b->last);
		root->stack_b->sec_last = get_second_last(root->stack_b->first);
		// printf("SEC LAST B:%p\n", root->stack_b->sec_last);
		root->stack_b->thi_last = get_third_last(root->stack_b->first);
}


t_elem	*get_second_last(t_elem *first)
{
	t_elem *probe;

	if (!first || !first->next || !first->next->next)
		return (NULL);
	probe = first;
	while(probe->next->next)
		probe = probe->next;
	return (probe);
}

t_elem	*ps_lstnew(int value)
{
	struct s_elem	*ptr;

	ptr = (struct s_elem *)malloc(sizeof(struct s_elem));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
}

t_elem	*ps_lstlast(t_elem *lst)
{
	// printf("LAST\n");
	if (!lst)
		return (NULL);
	int i = 0;
	while (lst->next)
	{
		if (i++ > 20)
			printf("lst:%p\n", lst);
		lst = lst->next;
	}
	// printf("lst:%p\n", lst);
	return (lst);
}

void	ps_lstadd_back(t_elem **lst, t_elem *new)
{
	struct s_elem	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
}

void	print_node(t_elem *node)
{
	printf("\n");
	// printf("node:%p\n", node);
	printf("node->value:%d\n", node->value);
	// printf("node->next:%p\n", node->next);
	printf("\n");
}

void	print_stack(t_stack *stack)
{
	t_elem	*probe;
	int		i;

	if (!stack)
		return ;
	probe = stack->first;
	i = 0;
	while (probe && i < 20)
	{
		print_node(probe);
		probe = probe->next;
		i++;
	}
	printf("[%d] NODES\n", i);
}

void	print_both(t_root *root)
{
	static int	i;

	printf("\nPRINT BOTH [%d]\n", i++);
	printf("\nPRINTING STACK A\n");
	root->stack_a ? print_stack(root->stack_a) : printf("STACK A EMPTY\n");
	printf("\nPRINTING STACK B\n");
	root->stack_b->first ? print_stack(root->stack_b) : printf("STACK B EMPTY\n");
	// print_root(root);
	printf("\n");
	printf("\nEND PRINT BOTH\n\n");
}

void	ft_error(errors error)
{
	char *str;
	str = NULL;
	switch (error)
	{
		case INPUT_NAN:
		str = "Invalid entry\n";
		break;
		case INPUT_OVERFLOW:
		str = "Input overflow\n";
		break;
		case INPUT_DOUBLE:
		str = "Input double\n";
		break;
		case PTR_ERROR:
		str = "Pointer error\n";
		break;
		case MALLOC_FAIL:
		str = "Malloc fail\n";
		break;
		case UNWANTED_BEHAVIOR:
		str = "Unwanted behavior\n";
		break;
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}