#include "push_swap.h"

static void check_numbers(char **input)
{
	int i;

	i = 1;
	while (input[i])
	{
		if (!is_number(input[i]))
			ft_error(INPUT_NAN);
		i++;
	}
}

static int check_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i > 11)
			return (i);
		i++;
	}
	return (0);
}

static void check_input(char **input)
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
			ft_error(INPUT_OVERFLOW);
		j = i + 1;
		while (input[j])
		{
			// printf("VALUE|%ld|\n", value);
			// printf("VALUE2|%ld|\n", ft_atol(input[j]));
			if (value == ft_atol(input[j]))
				ft_error(INPUT_DOUBLE);
			j++;
		}
		i++;
	}
}

struct s_elem *fill_stack(char **input)
{
	t_elem *new;
	t_elem *first;
	int i;

	check_input(input);
	new = NULL;
	i = 1;
	first = ps_lstnew(ft_atol(input[i]));
	if (!first)
		ft_error(MALLOC_FAIL);
	i++;
	while (input[i])
	{
		new = ps_lstnew(ft_atol(input[i]));
		if (!new)
			ft_error(MALLOC_FAIL);
		ps_lstadd_back(&first, new);
		i++;
	}
	return (first);
}

void init_stacks(t_root *root, char **input)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		ft_error(MALLOC_FAIL);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		ft_error(MALLOC_FAIL);

	stack_a->first = fill_stack(input);
	stack_a->last = ps_lstlast(stack_a->first);
	stack_a->sec_last = get_second_last(stack_a->first);
	stack_a->thi_last = get_third_last(stack_a->first);

	stack_b->first = NULL;
	stack_b->last = NULL;
	stack_b->sec_last = NULL;
	stack_a->thi_last = NULL;

	root->stack_a = stack_a;
	root->stack_b = stack_b;
}

void	init_data(t_root *root, char **input)
{
	int i;
	t_data *data;	

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error(MALLOC_FAIL);
	i = 1;
	while (input[i])
		i++;
	root->data = data;
	root->data->size_a = i;
	root->data->size_b = 0;
}

t_root *init_root(char **input)
{
	t_root *root;

	root = malloc(sizeof(t_root));
	if (!root)
		ft_error(MALLOC_FAIL);
	init_data(root, input);
	init_stacks(root, input);
	return (root);
}