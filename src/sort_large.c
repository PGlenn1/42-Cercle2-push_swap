#include "../includes/push_swap.h"

op_call	find_index(t_stack *stack, int index, int median, int limit)
{
	if (index >= median)
		return (rev_or_rot(stack, index, median));
	else
		return (rev_or_rot(stack, index, limit));
}

void	sort_large_numbers_ops_b(t_stack *stack_a, t_stack *stack_b,
		t_limits *limits, int target_index)
{
	if (stack_b->first->index == target_index)
		push_ab(stack_b, stack_a);
	else if (target_index <= limits->limit_a)
		stack_b->operator= find_index(stack_b, target_index, limits->median_a,
				0);
	else if (target_index <= limits->limit_b)
		stack_b->operator= find_index(stack_b, target_index, limits->median_b,
				limits->limit_a);
	else if (target_index <= limits->limit_c)
		stack_b->operator= find_index(stack_b, target_index, limits->median_c,
				limits->limit_b);
	else if (target_index <= limits->limit_d)
		stack_b->operator= find_index(stack_b, target_index, limits->median_d,
				limits->limit_c);
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
	while (!final_is_sorted(root))
	{
		root->stack_a->order = stack_is_sorted(root->stack_a);
		if ((root->stack_a->size == 1 || root->stack_a->order == INCREASING)
			&& root->stack_a->last->index == root->limits->limit_d - 1)
			sort_large_numbers_ops_b(root->stack_a, root->stack_b, root->limits,
					root->stack_a->first->index - 1);
		else
			sort_large_numbers_ops_a(root->stack_a, root->stack_b,
					root->limits);
		call_combined_ops(root);
	}
}
