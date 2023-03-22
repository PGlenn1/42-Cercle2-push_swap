#include "push_swap.h"

static void	check_numbers(char **input)
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

static int	check_len(char *str)
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

static void	check_input(char **input)
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

static t_stack *init_stack_a(char **input)
{
	t_stack *stack_a;
	t_stack *new;
	int i;

	check_input(input);
	i = 1;
	new = NULL;
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