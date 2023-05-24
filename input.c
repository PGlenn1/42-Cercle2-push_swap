#include "push_swap.h"

int	check_numbers(char **input)
{
	int	i;

	i = 1;
	while (input[i])
	{
		if (!is_number(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 11)
			return (0);
		i++;
	}
	return (1);
}

void	assign_index(t_stack *stack_a, int *array)
{
	int		i;
	t_elem	*probe;

	i = 0;
	while (i < stack_a->size)
	{
		probe = stack_a->first;
		while (probe->value != array[i])
			probe = probe->next;
		if (probe->value == array[i])
			probe->index = i;
		i++;
	}
}

int	pre_sort(t_stack *stack)
{
	int		i;
	int		*array;
	t_elem	*probe;

	array = malloc(sizeof(int) * stack->size);
	if (!array)
		return (0);
	probe = stack->first;
	i = 0;
	while (probe)
	{
		array[i] = probe->value;
		probe = probe->next;
		i++;
	}
	bubble_sort(array, stack->size);
	assign_index(stack, array);
	free(array);
	return (1);
}

int	check_input(char **input)
{
	int		i;
	int		j;
	long	value;

	i = 1;
	j = i + 1;
	value = 0;
	check_numbers(input);
	while (input[i])
	{
		value = ft_atol(input[i]);
		if (value > INT_MAX || value < INT_MIN || !check_len(input[i]))
			return (0);
		j = i + 1;
		while (input[j])
		{
			if (value == ft_atol(input[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

struct s_elem	*fill_stack(t_stack *stack, char **input)
{
	t_elem	*new;
	t_elem	*first;
	int		i;

	if (!check_input(input))
		return (NULL);
	new = NULL;
	i = 1;
	first = ps_lstnew(ft_atol(input[i]));
	if (!first)
		return (NULL);
	i++;
	while (input[i])
	{
		new = ps_lstnew(ft_atol(input[i]));
		if (!new)
			return (NULL);
		ps_lstadd_back(&first, new);
		i++;
	}
	stack->last = ps_lstlast(first);
	stack->size = i - 1;
	return (first);
}

t_limits	*init_segment_values(t_root *root)
{
	t_limits	*limits;

	limits = malloc(sizeof(t_limits));
	if (!limits)
		ft_free_all(root);
	limits->segment_size = root->input_size / 4;
	limits->limit_a = limits->segment_size;
	limits->limit_b = limits->segment_size * 2;
	limits->limit_c = limits->segment_size * 3;
	limits->limit_d = root->input_size;
	limits->median_a = limits->segment_size / 2;
	limits->median_b = limits->limit_a + limits->median_a;
	limits->median_c = limits->limit_b + limits->median_a;
	limits->median_d = limits->limit_c + limits->median_a;
	return (limits);
}

void	init_stack_values(t_root *root, char **input)
{
	root->stack_a->first = fill_stack(root->stack_a, input);
	if (!root->stack_a->first || !pre_sort(root->stack_a))
		ft_free_all(root);
	root->stack_a->ab = 'a';
	root->stack_a->operator= NOT_SET;
	root->stack_a->order = stack_is_sorted(root->stack_a);
	root->input_size = root->stack_a->size;
	root->limits = init_segment_values(root);
	root->stack_b->first = NULL;
	root->stack_b->last = NULL;
	root->stack_b->size = 0;
	root->stack_b->ab = 'b';
	root->stack_b->operator= NOT_SET;
	root->stack_b->order = NOT_SORTED;
}

void	init_stacks(t_root *root, char **input)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		ft_free_all(root);
	root->stack_a = stack_a;
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		ft_free_all(root);
	root->stack_b = stack_b;
	init_stack_values(root, input);
}

t_root	*init_root(char **input)
{
	t_root *root;

	root = malloc(sizeof(t_root));
	if (!root)
		ft_free_all(root);
	init_stacks(root, input);
	return (root);
}