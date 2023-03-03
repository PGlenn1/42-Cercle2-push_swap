#include "push_swap.h"

// check_input TODO

t_stack	*init_stack_a(int *int_values, int arr_size)
{
	t_stack	*first;
	t_stack	*new;
	int		i;

	if (!int_values)
		return (NULL);
	first = ps_lstnew(int_values[0]);
	new = NULL;
	i = 1;
	while (i < arr_size)
	{
		new = ps_lstnew(int_values[i]);
		ps_lstadd_back(&first, new);
		i++;
	}
	return (first);
}

void	push_swap(t_root *root)
{
	print_both(root);
	// rrr(root);
	// print_both(root);
	// rrr(root);
	// print_both(root);
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
	root->data = NULL;
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