#include "../includes/push_swap.h"

op_call	find_index(t_stack *stack, int index, int median, int limit)
{
	if (index >= median)
		return (rev_or_rot(stack, index, median));
	else
		return (rev_or_rot(stack, index, limit));
}

int	optimize(t_stack *stack_a, t_stack *stack_b, int target_index)
{
	printf("OPTIMIZE\n");
	// if (stack_a->size > 1 && stack_a->last->index
	// 	- stack_a->last->prev->index == 1)
	// {
	// 	printf("OPTI 1\n");
	// 	push_ab(stack_b, stack_a);
	// }
	if (stack_a->last->index == target_index)
	{
		stack_a->
		operator= REV_ROT;
		printf("OPTI 2\n");
	}
	else if (stack_a->size == 1 || stack_b->first->index == stack_a->last->index
			+ 1)
	{
		push_ab(stack_b, stack_a);
		stack_a->operator= ROT;
		printf("OPTI 3\n");
	}
	return (1);
}

void	sort_large_numbers_ops_b(t_stack *stack_a, t_stack *stack_b,
		t_limits *limits, int target_index)
{
	static int	i;

	printf("SORT OPS B\n");
	printf("TARGET:%d\n", target_index);
	i++;
	printf("ITER:%d\n", i);
	// if (i > 5)
	// 	exit(0);
	if (stack_b->first->index == target_index)
	{
		printf("DEBUG\n");
		push_ab(stack_b, stack_a);
	}
	else if (optimize(stack_a, stack_b, target_index)
			&& target_index <= limits->limit_a)
		stack_b->operator= find_index(stack_b, target_index, limits->median_a,
				0);
	else if (optimize(stack_a, stack_b, target_index)
			&& target_index <= limits->limit_b)
		stack_b->operator= find_index(stack_b, target_index, limits->median_b,
				limits->limit_a);
	else if (optimize(stack_a, stack_b, target_index)
			&& target_index <= limits->limit_c)
		stack_b->operator= find_index(stack_b, target_index, limits->median_c,
				limits->limit_b);
	else if (optimize(stack_a, stack_b, target_index)
			&& target_index <= limits->limit_d)
		stack_b->operator= find_index(stack_b, target_index, limits->median_d,
				limits->limit_c);
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
	printf("SORT OPS A\n");
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
	int	target_index;
	int	phase_b;

	target_index = 0;
	phase_b = 0;
	while (!final_is_sorted(root))
	{
		root->stack_a->order = stack_is_sorted(root->stack_a);
		if (phase_b)
		{
			target_index = root->stack_a->first->index - 1;
			sort_large_numbers_ops_b(root->stack_a, root->stack_b, root->limits,
					target_index);
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
