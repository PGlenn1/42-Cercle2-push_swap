#include "push_swap.h"

// check_input TODO


void	push_swap(t_root *root)
{
	print_both(root);
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
	int i;

	check_input(input);
	stack_a = ps_lstnew(ft_atol(input[1]));
	if (!stack_a)
		return (NULL);
	new = NULL;
	i = 2;
	while(input[i])
	{
		new = ps_lstnew(ft_atol(input[i]));
		if (!new)
			return (NULL);
		ps_lstadd_back(&stack_a, new);
		i++;
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