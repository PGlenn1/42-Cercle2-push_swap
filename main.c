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

void	check_doubles(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

void	check_input(char **argv) // TODO CHECK OVERFLOW
{
	unsigned int i;
	unsigned int j;
	long value;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				ft_error();
			j++;
			if (argv[i] > INT_MAX || argv[i] < INT_MIN)
				ft_error();
		}
		i++;
	}
	check_doubles(argv);
}

t_stack	*format_input(char **argv)
{
	t_stack	*stack_a;
	int		*int_values;
	int		arr_size;
	int		i;

	arr_size = 0;
	while (argv[arr_size + 1])
		arr_size++;
	int_values = malloc(sizeof(long) * (arr_size + 1));
	if (!int_values)
		return (NULL);
	i = 0;
	while (i < arr_size)
	{
		int_values[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	stack_a = init_stack_a(int_values, arr_size);
	return (stack_a);
}

t_root	*init_root(char **argv)
{
	t_root	*root;
	t_stack	*stack_a;

	root = malloc(sizeof(struct s_root));
	if (!root)
		return (NULL);
	stack_a = format_input(argv);
	root->stack_a = stack_a;
	root->data = NULL;
	root->stack_b = NULL;
	return (root);
}

int	main(int argc, char **argv)
{
	t_root *root;

	if (argc < 2)
		return (0);
	check_input(argv);
	root = init_root(argv);
	push_swap(root);
	return (0);
}