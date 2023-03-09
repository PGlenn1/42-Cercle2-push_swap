#include "push_swap.h"

t_stack	*ps_lstprev(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*ps_lstnew(int value)
{
	struct s_stack	*ptr;

	ptr = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!ptr)
		return (NULL);
	ptr->prev = NULL;
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	// printf("LAST\n");
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		// printf("lst:%p\n", lst);
		lst = lst->next;
	}
	// printf("lst:%p\n", lst);
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	struct s_stack	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ps_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

void	print_node(t_stack *node)
{
	printf("\n");
	// printf("node->prev:%p\n", node->prev);
	// printf("node:%p\n", node);
	printf("node->value:%d\n", node->value);
	// printf("node->next:%p\n", node->next);
}

void	print_stack(t_stack *stack)
{
	t_stack	*probe;
	int		i;

	probe = stack;
	printf("stack:%p\n", stack);
	i = 0;
	while (probe && i < 10)
	{
		print_node(probe);
		probe = probe->next;
	}
	printf("\nEND PRINT STACK\n\n");
}

void	print_both(t_root *root)
{
	static int	i;

	i = 0;
	printf("\nPRINT BOTH [%d]\n", i++);
	printf("\nPRINTING STACK A\n");
	root->stack_a ? print_stack(root->stack_a) : printf("STACK A EMPTY\n");
	printf("PRINTING STACK B\n");
	root->stack_b ? print_stack(root->stack_b) : printf("STACK B EMPTY\n");
	printf("\n");
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}