#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_elem *probe;
	int	value;

	printf("IS SORTED ?\n");
	probe = stack->first;
	value = 0;
	if (!probe || !probe->next)
		return (0);
	while (probe && probe->next)
	{
		value = probe->value;
		if (value == probe->next->value)
			ft_error(UNWANTED_BEHAVIOR);
		if (value < probe->next->value)
		{
			printf("Not sorted\n");
			return (0);
		}
		probe = probe->next;
	}
	printf("Yes\n");
	return (1);
}

int	get_stack_size(t_stack *stack)
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


// t_elem	*get_third_last(t_stack *stack)
// {
// 	t_elem *probe;

// 	if (!stack || !stack->first || !stack->first->next || !stack->first->next->next || !stack->first->next->next->next)
// 		return (NULL);
// 	probe = stack->first;
// 	while (probe->next->next->next)
// 		probe = probe->next;
// 	return (probe);
// }

void print_stack_ptrs(t_root *root)
{
		// printf("FIRST A:%p\n", root->stack_a->first);
		// printf("LAST A:%p\n", root->stack_a->last);
		// printf("SC LAST A:%p\n", root->stack_a->sec_last);
		// printf("THI LAST A:%p\n", root->stack_a->thi_last);
		// printf("FIRST B:%p\n", root->stack_b->first);
		// printf("LAST B:%p\n", root->stack_b->last);
		// printf("SEC LAST B:%p\n", root->stack_b->sec_last);
		// printf("THI LAST B:%p\n", root->stack_b->thi_last);
		printf("-----\nsize A:%d\n", root->stack_a->size);
		printf("-----\nsize B:%d\n", root->stack_b->size);
}

void print_result(t_stack *stack)
{
	t_elem *probe;

	printf("\n");
	probe = stack->first;
	while (probe->next)
	{
		printf("--> %d ", probe->value);
		probe = probe->next;
	}
	printf("--> %d", probe->value);
	printf("\n\n");
}

void	update_stack_ptrs(int size, t_stack *stack) /// Should be reworked entirely as for less function calls
{
	 	printf("UPDATE STACK PTRS\n");
		
		if (size == 0)
		{
			stack->first = NULL;
		}
		if (size > 1)
		{
			stack->second = stack->first->next;
		}
		if (size > 2)
		{
			stack->sec_last = stack->last->prev;	
		}
		if (size > 3)
		{
			stack->thi_last = stack->sec_last->prev;
		}
}


// t_elem	*get_second_last(t_stack *stack)
// {
// 	t_elem *probe;

// 	if (!stack || !stack->first || !stack->first->next || !stack->first->next->next)
// 		return (NULL);
// 	probe = stack->first;
// 	while(probe->next->next)
// 		probe = probe->next;
// 	return (probe);
// }

t_elem	*ps_lstnew(int value)
{
	struct s_elem	*ptr;

	ptr = (struct s_elem *)malloc(sizeof(struct s_elem));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->prev = NULL;
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
	printf("node:%p\n", node);
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
	// if (stack->first && stack->thi_last && stack->last)
	// 	print_sort_values(stack->first->value, stack->thi_last->value, stack->last->value);
	printf("[%d] NODES\n", i);
}

void	print_both(t_root *root)
{
	static int	i;

	printf("\n-------\nPRINT BOTH [%d]\n", i++);
	// printf("\nPRINTING STACK A\n");

	// root->stack_a ? print_stack(root->stack_a) : printf("\nSTACK A EMPTY\n");
	// printf("\nPRINTING STACK B\n");
	// root->stack_b->first ? print_stack(root->stack_b) : printf("\nSTACK B EMPTY\n");
	// printf("\n");
	print_stack_ptrs(root);
	if (root->stack_a->first)
		print_result(root->stack_a);
	if (root->stack_b->first)
		print_result(root->stack_b);
	else
		printf("--> EMPTY\n");
	printf("\n");
	if (i > 15)
		ft_error(UNWANTED_BEHAVIOR);
	// if (root->stack_a->first && root->stack_a->sec_last && root->stack_a->last) 
	// 	print_sort_values(root->stack_a->first->value, root->stack_a->sec_last->value, root->stack_a->last->value);
	// printf("\nEND PRINT BOTH\n\n");
}

void	ft_error(errors error)
{
	char *str;
	str = NULL;
	switch (error)
	{
		case NAN:
		str = "Invalid entry\n";
		break;
		case ALREADY_SORTED:
		str = "Input already sorted\n";
		break;
		case OVERFLOW:
		str = "Input overflow\n";
		break;
		case DOUBLE:
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
		case DEBUG:
		str = "Debug\n";
		break;
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd("Error\n", 2);
	if (error != DEBUG)
		exit(1);
}