#include "../includes/push_swap.h"

op_call	find_index(t_stack *stack, int index, int median, int limit)
{
	if (index >= median)
		return (rev_or_rot(stack, index, median));
	else
		return (rev_or_rot(stack, index, limit));
}

// int	optimize(t_stack *stack_a, t_stack *stack_b, t_limits *limits,
// 		int target_index)
// {
// 	// ft_printf("OPTIMIZE\n");
// 	if (stack_a->last->index == target_index)
// 	{
// 		stack_a->
// 		operator= REV_ROT;
// 		ft_printf("OPTI 1\n");
// 	}
// 	else if (stack_b->last->index == limits->limit_d - 1)
// 	{
// 		stack_b->operator= rev_or_rot(stack_b, )
// 	}
// 	else if (stack_b->first->index == stack_a->last->index + 1)
// 	{
// 		if (stack_a->operator== NOT_SET)
// 			push_ab(stack_b, stack_a);
// 		stack_a->operator= ROT;
// 		ft_printf("OPTI 2\n");
// 	}
// 	return (1);
// }

int	get_current_segment(t_stack *stack, t_limits *limits)
{
	if (stack->first->index - 1 >= limits->median_d)
		return (limits->median_d);
	else if (stack->first->index - 1 >= limits->limit_c)
		return (limits->limit_c);
	else if (stack->first->index - 1 >= limits->median_c)
		return (limits->median_c);
	else if (stack->first->index - 1 >= limits->limit_b)
		return (limits->limit_b);
	else if (stack->first->index - 1 >= limits->median_b)
		return (limits->median_b);
	else if (stack->first->index - 1 >= limits->limit_a)
		return (limits->limit_a);
	else if (stack->first->index - 1 >= limits->median_a)
		return (limits->median_a);
	return (0);
}

void	sort_large_numbers_ops_b(t_stack *stack_a, t_stack *stack_b,
		t_limits *limits)
{
	int			current_segment;
	static int	i;

	i++;
	ft_printf("SORT OPS B\n");
	ft_printf("ITER:%d\n", i);
	// if (stack_a->last->index != limits->limit_d - 1)
	// 	exit(0);
	// if (i > 150)
	// 	exit(0);
	current_segment = get_current_segment(stack_a, limits);
	printf("CURRENT:%d\n", current_segment);
	if (stack_b->first->index == stack_a->first->index - 1)
		push_ab(stack_b, stack_a);
	if (stack_a->last->index == stack_a->first->index - 1)
	{
		ft_printf("DEBUG 3\n");
		stack_a->operator= REV_ROT;
	}
	else if (stack_b->first->index == stack_a->last->index + 1)
	{
		ft_printf("DEBUG 2\n");
		push_ab(stack_b, stack_a);
		stack_a->operator= ROT;
	}
	if (stack_a->last->index == limits->limit_d)
	{
		ft_printf("DEBUG\n");
		stack_b->operator= rev_or_rot(stack_b, current_segment,
				current_segment);
		if (stack_b->first->index == current_segment)
		{
			push_ab(stack_b, stack_a);
			stack_a->operator= ROT;
		}
	}
	else
	{
		stack_b->operator= rev_or_rot(stack_b, stack_a->last->index + 1,
				current_segment);
	}
	// ft_printf("TARGET:%d\n", target_index);
	// if (stack_b->size > 0 && stack_b->first->index == target_index)
	// {
	// 	// ft_printf("DEBUG\n");
	// 	push_ab(stack_b, stack_a);
	// }
	// else if (optimize(stack_a, stack_b, limits, target_index)
	// 		&& target_index <= limits->limit_a)
	// 	stack_b->operator= find_index(stack_b, target_index, limits->median_a,
	// 			0);
	// else if (optimize(stack_a, stack_b, limits, target_index)
	// 		&& target_index <= limits->limit_b)
	// 	stack_b->operator= find_index(stack_b, target_index, limits->median_b,
	// 			limits->limit_a);
	// else if (optimize(stack_a, stack_b, limits, target_index)
	// 		&& target_index <= limits->limit_c)
	// 	stack_b->operator= find_index(stack_b, target_index, limits->median_c,
	// 			limits->limit_b);
	// else if (optimize(stack_a, stack_b, limits, target_index)
	// 		&& target_index <= limits->limit_d)
	// 	stack_b->operator= find_index(stack_b, target_index, limits->median_d,
	// 			limits->limit_c);
	// if (stack_a->first->index == 159)
	// 	exit(1);
}

void	push_segment(t_stack *from, t_stack *to, int limit, int median)
{
	if (from->first->index <= limit)
	{
		push_ab(from, to);
		if (to->size > 1 && to->first->index < median)
			to->operator= ROT;
	}
	if (from->size > 1 && from->first->index > limit)
		from->operator= ROT;
}

void	sort_large_numbers_ops_a(t_stack *stack_a, t_stack *stack_b,
		t_limits *limits)
{
	ft_printf("SORT OPS A\n");
	if (stack_a->first->index == limits->limit_d - 1)
		stack_a->operator= ROT;
	else if (stack_b->size > limits->limit_c)
		push_segment(stack_a, stack_b, limits->limit_d, limits->median_d);
	else if (stack_b->size > limits->limit_b)
		push_segment(stack_a, stack_b, limits->limit_c, limits->median_c);
	else if (stack_b->size > limits->limit_a)
		push_segment(stack_a, stack_b, limits->limit_b, limits->median_b);
	else if (stack_b->size >= 0)
		push_segment(stack_a, stack_b, limits->limit_a, limits->median_a);
}

void	sort_large_numbers(t_root *root)
{
	int	phase_b;

	phase_b = 0;
	while (!final_is_sorted(root))
	{
		root->stack_a->order = stack_is_sorted(root->stack_a);
		if (phase_b)
		{
			sort_large_numbers_ops_b(root->stack_a, root->stack_b,
					root->limits);
		}
		else
		{
			sort_large_numbers_ops_a(root->stack_a, root->stack_b,
					root->limits);
			if (root->stack_a->size == 1)
				phase_b = 1;
		}
		call_combined_ops(root);
		print_both(root);
		// if (root->stack_a->last->index == 156
		// 	&& root->stack_a->last->prev->index == 170)
		// 	exit(1);
	}
}
