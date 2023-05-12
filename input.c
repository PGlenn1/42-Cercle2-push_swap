#include "push_swap.h"

static void	check_numbers(char **input)
{
	int	i;

	i = 1;
	while (input[i])
	{
		if (!is_number(input[i]))
			ft_error(NAN);
		i++;
	}
}

static int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 11)
			return (i);
		i++;
	}
	return (0);
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

void	pre_sort(t_root *root, t_stack *stack)
{
	int		i;
	int		*array;
	t_elem	*probe;

	array = malloc(sizeof(int) * stack->size);
	if (!array)
		ft_error(MALLOC_FAIL);
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
	root->array = array;
	// stack->median = array[stack->size / 2];
	print_array(array, stack->size);
	// free(array);
}

static void	check_input(char **input)
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
		if (value > INT_MAX || value < INT_MIN || check_len(input[i]))
			ft_error(OVERFLOW);
		j = i + 1;
		while (input[j])
		{
			if (value == ft_atol(input[j]))
			{
				printf("DOUBLE:%ld\n", value);
				ft_error(DOUBLE);
			}
			j++;
		}
		i++;
	}
}

struct s_elem	*fill_stack(t_stack *stack, char **input)
{
	t_elem	*new;
	t_elem	*first;
	int		i;

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
	stack->last = ps_lstlast(first);
	stack->size = i - 1;
	return (first);
}

void	init_stack_values(t_root *root, char **input)
{
	root->stack_a->first = fill_stack(root->stack_a, input);
	pre_sort(root, root->stack_a);
	root->stack_a->median = 0;
	root->stack_a->segment = 0;
	root->stack_a->ab = 'a';
	root->stack_a->operator= NOT_SET;
	root->stack_a->order = stack_is_sorted(root->stack_a);
	root->ops = 0;
	root->input_size = root->stack_a->size;
	root->stack_b->first = NULL;
	root->stack_b->last = NULL;
	root->stack_b->size = 0;
	root->stack_b->median = 0;
	root->stack_b->segment = 0;
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
		ft_error(MALLOC_FAIL);
	root->stack_a = stack_a;
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		ft_error(MALLOC_FAIL);
	root->stack_b = stack_b;
	root->ops = 0;
	init_stack_values(root, input);
}

t_root	*init_root(char **input)
{
	t_root *root;

	root = malloc(sizeof(t_root));
	if (!root)
		ft_error(MALLOC_FAIL);
	init_stacks(root, input);
	return (root);
}