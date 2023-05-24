#include "push_swap.h"

order_type	stack_is_sorted(t_stack *stack)
{
	t_elem	*probe;

	// printf("INCR SORTED\n");
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
	printf("\n");
	printf("SORT OPTIONS\n");
	printf("%d -> %d -> %d\n", first, middle, last);
	printf("\n");
}

void	print_node(t_elem *node)
{
	printf("\n");
	printf("node->prev:%p\n", node->prev);
	printf("node->value:%d\n", node->value);
	printf("node->index:%d\n", node->index);
	printf("node:%p\n", node);
	printf("node->next:%p\n", node->next);
	printf("\n");
}

void	print_result(t_stack *stack)
{
	t_elem	*probe;

	printf("\nPRINT RESULT\n");
	if (!stack->first)
	{
		printf("STACK EMPTY\n");
		return ;
	}
	probe = stack->first;
	while (probe->next)
	{
		printf("--> %d |", probe->index);
		probe = probe->next;
	}
	printf("--> %d\n", probe->index);
	printf("\n\n");
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
	printf("-----\nSize:%d\n", stack->size);
}

void	print_indexes(t_root *root, t_limits *limits)
{
	printf("FIRST INDEX[0]:%d\n", root->array[0]);
	printf("MED A[%d]\n", limits->median_a);
	printf("LIMIT A[%d]\n", limits->limit_a);
	printf("MED B[%d]\n", limits->median_b);
	printf("LIMIT B[%d]\n", limits->limit_b);
	printf("MED C[%d]\n", limits->median_c);
	printf("LIMIT C[%d]\n", limits->limit_c);
	printf("MED D[%d]\n", limits->median_d);
	printf("LIMIT D[%d]\n", limits->limit_d);
	printf("LAST INDEX = %d\n", root->input_size - 1);
}

void	print_both(t_root *root)
{
	static int	i;

	printf("\n-------\nPRINT BOTH [%d]\n", i++);
	print_indexes(root, root->limits);
	printf("\nPRINTING STACK A\n");
	if (root->stack_a->first)
	{
		printf("size_a:%d\n", root->stack_a->size);
		print_result(root->stack_a);
	}
	else
		printf("--> EMPTY\n");
	printf("\nPRINTING STACK B\n");
	if (root->stack_b->first)
	{
		printf("size_b:%d\n", root->stack_b->size);
		print_result(root->stack_b);
	}
	else
		printf("--> EMPTY\n");
	// if (i > 60)
	// 	ft_error(UNWANTED_BEHAVIOR);
	if (root->ops + root->stack_a->ops + root->stack_b->ops >= 700)
	{
		// printf("ops:%d\n", root->ops + root->stack_a->ops
		// + root->stack_b->ops);
		printf("TOO MANY OPS\n");
		// ft_error(UNWANTED_BEHAVIOR);
	}
	printf("ops:%d\n", root->ops + root->stack_a->ops + root->stack_b->ops);
	printf("\nEND PRINT BOTH\n\n");
}

void	ft_free_stack(t_stack *stack)
{
	t_elem	*probe;
	t_elem	*tmp;

	probe = stack->first;
	tmp = probe;
	while (probe)
	{
		tmp = probe;
		probe = probe->next;
		free(tmp);
	}
}

void	ft_free_all(t_root *root)
{
	if (root->stack_a)
		ft_free_stack(root->stack_a);
	if (root->stack_b)
		ft_free_stack(root->stack_b);
	if (root->limits)
		free(root->limits);
	if (root->array)
		free(root->array);
	free(root);
	// ft_putstr_fd("Error\n", 2);
	// exit(1);
}

void	ft_error(errors error)
{
	char *str;
	str = NULL;
	switch (error)
	{
	case NAN:
		str = "Invalid entry\n";
		break ;
	case ALREADY_SORTED:
		str = "Input already sorted\n";
		break ;
	case OVERFLOW:
		str = "Input overflow\n";
		break ;
	case DOUBLE:
		str = "Input double\n";
		break ;
	case PTR_ERROR:
		str = "Pointer error\n";
		break ;
	case MALLOC_FAIL:
		str = "Malloc fail\n";
		break ;
	case UNWANTED_BEHAVIOR:
		str = "Unwanted behavior\n";
		break ;
	case DEBUG:
		str = "Debug\n";
		break ;
	}
	// ft_free_all(root);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("Error\n", 2);
	if (error != DEBUG)
		exit(1);
}