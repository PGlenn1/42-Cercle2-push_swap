#include "push_swap.h"

int	incr_sorted(t_stack *stack)
{
	t_elem	*probe;
	int		value;

	// printf("INCR SORTED\n");
	probe = stack->first;
	value = 0;
	while (probe && probe->next)
	{
		value = probe->value;
		if (value == probe->next->value)
			ft_error(UNWANTED_BEHAVIOR);
		if (value > probe->next->value)
		{
			// print_result(stack);
			return (0);
		}
		probe = probe->next;
	}
	return (1);
}

int	decr_sorted(t_stack *stack)
{
	t_elem	*probe;
	int		value;

	// printf("DECR SORTED\n");
	probe = stack->first;
	value = 0;
	while (probe && probe->next)
	{
		value = probe->value;
		if (value == probe->next->value)
			ft_error(UNWANTED_BEHAVIOR);
		if (value < probe->next->value)
		{
			// print_result(stack);
			// printf("Not sorted\n");
			return (0);
		}
		probe = probe->next;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	printf("IS SORTED ?\n");
	if (!stack || !stack->first)
		ft_error(PTR_ERROR);
	printf("DEBUGITOOOOO\n");
	print_result(stack);
	if (incr_sorted(stack))
	{
		stack->order = INCREASING;
		return (1);
	}
	else if (decr_sorted(stack))
	{
		stack->order = DECREASING;
		return (1);
	}
	else
	{
		stack->order = NOT_SORTED;
		return (0);
	}
}

int	get_stack_size(t_stack *stack) // Only for dev
{
	t_elem *probe;
	int size;

	probe = stack->first;
	size = 0;
	while (probe)
	{
		size++;
		probe = probe->next;
	}
	return (size);
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
	printf("node:%p\n", node);
	printf("node->value:%d\n", node->value);
	printf("node->next:%p\n", node->next);
	printf("\n");
}

void	print_result(t_stack *stack)
{
	t_elem	*probe;

	printf("\nPRINT RESULT\n");
	probe = stack->first;
	while (probe->next)
	{
		printf("--> %d ", probe->value);
		probe = probe->next;
	}
	printf("--> %d", probe->value);
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
	printf("-----\nSize:%d\n", get_stack_size(stack));
}

void	print_both(t_root *root)
{
	static int	i;

	printf("\n-------\nPRINT BOTH [%d]\n", i++);
	// root->stack_a->first ? print_stack(root->stack_a) : printf("\nSTACK A EMPTY\n");
	// root->stack_b->first ? print_stack(root->stack_b) : printf("\nSTACK B EMPTY\n");
	// printf("\n");
	printf("\n");
	printf("\nPRINTING STACK A\n");
	if (root->stack_a->first)
		print_result(root->stack_a);
	else
		printf("--> EMPTY\n");
	printf("\nPRINTING STACK B\n");
	if (root->stack_b->first)
		print_result(root->stack_b);
	else
		printf("--> EMPTY\n");
	if (i > 15)
		ft_error(UNWANTED_BEHAVIOR);
	printf("\nEND PRINT BOTH\n\n");
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
	ft_putstr_fd(str, 2);
	ft_putstr_fd("Error\n", 2);
	if (error != DEBUG)
		exit(1);
}