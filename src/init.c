#include "../includes/push_swap.h"

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
		{
			if (!first->next)
				free(first);
			return (NULL);
		}
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
		ft_free_all(root, 1);
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
	root->limits = NULL;
	root->stack_a->first = fill_stack(root->stack_a, input);
	if (!root->stack_a->first || !pre_sort(root->stack_a))
		ft_free_all(root, 1);
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

	stack_b = NULL;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		ft_free_all(root, 1);
	root->stack_a = stack_a;
	stack_a->first = NULL;
	stack_a->last = NULL;
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		ft_free_all(root, 1);
	root->stack_b = stack_b;
	stack_b->first = NULL;
	stack_b->last = NULL;
	init_stack_values(root, input);
}

t_root	*init_root(char **input)
{
	t_root	*root;

	root = malloc(sizeof(t_root));
	if (!root)
		ft_free_all(root, 1);
	init_stacks(root, input);
	return (root);
}
