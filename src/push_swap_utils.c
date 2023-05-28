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
	struct s_elem	*last;

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

void	print_sort_values(int first, int middle, int last)
{
	ft_printf("\n");
	ft_printf("SORT OPTIONS\n");
	ft_printf("%d -> %d -> %d\n", first, middle, last);
	ft_printf("\n");
}

void	print_node(t_elem *node)
{
	ft_printf("\n");
	ft_printf("node->prev:%p\n", node->prev);
	ft_printf("node->value:%d\n", node->value);
	ft_printf("node->index:%d\n", node->index);
	ft_printf("node:%p\n", node);
	ft_printf("node->next:%p\n", node->next);
	ft_printf("\n");
}

void	print_result(t_stack *stack)
{
	t_elem	*probe;

	ft_printf("\nPRINT RESULT\n");
	if (!stack->first)
	{
		ft_printf("STACK EMPTY\n");
		return ;
	}
	probe = stack->first;
	while (probe->next)
	{
		ft_printf("--> %d |", probe->index);
		probe = probe->next;
	}
	ft_printf("--> %d\n", probe->index);
	ft_printf("\n\n");
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
	ft_printf("-----\nSize:%d\n", stack->size);
}

void	print_indexes(t_root *root, t_limits *limits)
{
	ft_printf("INDEXES\n");
	ft_printf("MED A[%d]\n", limits->median_a);
	ft_printf("LIMIT A[%d]\n", limits->limit_a);
	ft_printf("MED B[%d]\n", limits->median_b);
	ft_printf("LIMIT B[%d]\n", limits->limit_b);
	ft_printf("MED C[%d]\n", limits->median_c);
	ft_printf("LIMIT C[%d]\n", limits->limit_c);
	ft_printf("MED D[%d]\n", limits->median_d);
	ft_printf("LIMIT D[%d]\n", limits->limit_d);
	ft_printf("LAST INDEX = %d\n", root->input_size - 1);
}

void	print_both(t_root *root)
{
	static int	i;

	ft_printf("\n-------\nPRINT BOTH [%d]\n", i++);
	print_indexes(root, root->limits);
	ft_printf("\nPRINTING STACK A\n");
	if (root->stack_a->first)
	{
		ft_printf("size_a:%d\n", root->stack_a->size);
		print_result(root->stack_a);
	}
	else
		ft_printf("--> EMPTY\n");
	ft_printf("\nPRINTING STACK B\n");
	if (root->stack_b->first)
	{
		ft_printf("size_b:%d\n", root->stack_b->size);
		print_result(root->stack_b);
	}
	else
		ft_printf("--> EMPTY\n");
	// if (i > 0)
	// 	exit(0);
	// if (root->ops + root->stack_a->ops + root->stack_b->ops >= 700)
	// {
	// 	// ft_printf("ops:%d\n", root->ops + root->stack_a->ops
	// 	// + root->stack_b->ops);
	// 	ft_printf("TOO MANY OPS\n");
	// 	// ft_error(UNWANTED_BEHAVIOR);
	// }
	// ft_printf("ops:%d\n", root->ops + root->stack_a->ops
	// + root->stack_b->ops);
	ft_printf("\nEND PRINT BOTH\n\n");
}
