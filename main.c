#include "push_swap.h"

// check_input TODO

t_stack	*init_stack_a(int *int_values, int arr_size)
{
	t_stack	*first;
	t_stack	*new;
	int		i;

	if (!int_values)
		return (NULL);
	first = ps_lstnew(int_values[0], 0);
	new = NULL;
	i = 1;
	while (i < arr_size)
	{
		new = ps_lstnew(int_values[i], i);
		ps_lstadd_back(&first, new);
		i++;
	}
	return (first);
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	printf("\nPRINT STACK\n");
	current = stack;
	while (current)
	{
		printf("\n");
		printf("value:%d\n", current->value);
		printf("index:%d\n", current->index);
		current = current->next;
	}
	printf("\nEND PRINT STACK\n");
}

void	push_swap(t_root *root)
{
	t_stack	*prev;

	print_stack(root->stack_a);
	prev = ps_lstprev(root->stack_a);
	printf("prev:%p\n", prev);
	printf("prev->value:%d\n", prev->value);
	swap_a(root);
	print_stack(root->stack_a);
}

//  TODO CHECK INPUT

t_stack	*format_input(char **split_input)
{
	t_stack	*stack_a;
	int		*int_values;
	int		arr_size;
	int		i;

	arr_size = 0;
	while (split_input[arr_size])
		arr_size++;
	int_values = malloc(sizeof(int) * (arr_size + 1));
	if (!int_values)
		return (NULL);
	i = 0;
	while (i < arr_size)
	{
		int_values[i] = ft_atoi(split_input[i]);
		i++;
	}
	stack_a = init_stack_a(int_values, arr_size);
	return (stack_a);
}

t_root	*init_root(char **split_input)
{
	t_root	*root;
	t_stack	*stack_a;

	root = malloc(sizeof(struct s_root));
	if (!root)
		return (NULL);
	stack_a = format_input(split_input);
	root->stack_a = stack_a;
	root->stack_b = NULL;
	return (root);
}

int	main(int argc, char **argv)
{
	t_root *root;

	(void)argc;
	root = init_root(ft_split(argv[1], ' '));
	push_swap(root);
	return (0);
}