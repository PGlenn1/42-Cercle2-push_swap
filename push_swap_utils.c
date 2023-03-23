#include "push_swap.h"

t_stack	*get_second_last(t_stack *stack)
{
	t_stack *probe;

	probe = stack;
	if (!stack || !probe->next || !probe->next->next)
		return (NULL);
	while(probe->next->next)
		probe = probe->next;
	return (probe);
}

t_stack	*ps_lstnew(int value)
{
	struct s_stack	*ptr;

	ptr = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
}

t_stack	*ps_lstlast(t_stack *lst)
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
}

void	print_root(t_root *root)
{
	printf("\nPRINT ROOT\n");
	if (root->first_a)
	{
		// printf("first_a:%p\n", root->first_a);
		printf("first_a:%d\n", root->first_a->value);
		if (root->first_a != root->last_a)
			printf("last_a:%d\n", root->last_a->value);
		else
			printf("Only 1 node\n");
		if (root->sec_last_a)
			printf("sec_last_a:%d\n", root->sec_last_a->value);
	}
	else
		printf("STACK A EMPTY\n");
	if (root->first_b)
	{
		printf("\nfirst_b:%d\n", root->first_b->value);
		if (root->first_b != root->last_b)
			printf("last_b:%d\n", root->last_b->value);
		else
			printf("Only 1 node\n");
		if (root->sec_last_b)
			printf("sec_last_b:%d\n", root->sec_last_b->value);
	}
	else
		printf("STACK B EMPTY\n");
	printf("\nEND PRINT ROOT\n\n");
}

void	print_node(t_stack *node)
{
	printf("\n");
	printf("node:%p\n", node);
	printf("node->value:%d\n", node->value);
	printf("node->next:%p\n", node->next);
}

void	print_stack(t_stack *stack)
{
	t_stack	*probe;
	int		i;

	probe = stack;
	printf("stack:%p\n", stack);
	i = 0;
	while (probe && i < 20)
	{
		// printf("WHILE\n");
		print_node(probe);
		probe = probe->next;
		i++;
	}
	printf("[%d] NODES\n", i);
	printf("\nEND PRINT STACK\n\n");
}

void	print_both(t_root *root)
{
	static int	i;

	printf("\nPRINT BOTH [%d]\n", i++);
	printf("\nPRINTING STACK A\n");
	root->first_a ? print_stack(root->first_a) : printf("STACK A EMPTY\n");
	printf("\nPRINTING STACK B\n");
	root->first_b ? print_stack(root->first_b) : printf("STACK B EMPTY\n");
	// print_root(root);
	printf("\n");
}

void	ft_error(const char *str)
{
	ft_putstr_fd((char *)str, 1);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}