#include "push_swap.h"

// check_input TODO


void	push_swap(t_root *root)
{
	print_both(root);
	// swap(root->stack_a, 'A');
	// push_b(root);
	// push_b(root);
	// push_b(root);
	// print_both(root);
	// swap(root->stack_a);
	// print_both(root);
	// swap_b(root->stack_a);
	// rrr(root);
	// print_both(root);
	// rrr(root);
	// print_both(root);
}

void	check_numbers(char **input)
{
	int i;

	i = 1;
	while (input[i])
	{
		if (!is_number(input[i]))
			ft_error("NOT A NUMBER\n");
		i++;
	}
}

int	check_len(char *str)
{
	int i;	

	i = 0;
	while (str[i])
	{
		if (i > 11)
			return(i);
		i++;
	}
	return (0);
}

void	check_input(char **input)
{
	int i;
	int j;
	long value;

	i = 1;
	j = i + 1;
	value = 0;
	check_numbers(input);
	while (input[i])
	{
		value = ft_atol(input[i]);
		if (value > INT_MAX || value < INT_MIN || check_len(input[i]))
			ft_error("OVERFLOW\n");
		j = i + 1;
		while (input[j])
		{
			// printf("VALUE|%ld|\n", value);
			// printf("VALUE2|%ld|\n", ft_atol(input[j]));
			if (value == ft_atol(input[j]))
				ft_error("DOUBLES\n");
			j++;
		}
		i++;
	}
}

t_stack *init_stack_a(char **input)
{
	t_stack *stack_a;
	t_stack *new;
	int size;

	check_input(input);
	size = 0;
	while (input[size])
		size++;
	new = NULL;
	size--;
	while(size >= 1)
	{
		new = ps_lstnew(ft_atol(input[size]));
		if (!new)
			return (NULL);
		ps_lstadd_back(&stack_a, new);
		size--;
	}
	return (stack_a);
}



t_root	*init_root(char **input)
{
	t_root *root;

	root = malloc(sizeof(t_root) * 1);
	if (!root)
		return (NULL);
	root->stack_a = init_stack_a(input);
	return (root);
}


int	main(int argc, char **argv)
{
	t_root *root;

	if (argc < 2)
		return (0);
	root = init_root(argv);
	if (!root)
		return (1);
	push_swap(root);
	return (0);
}