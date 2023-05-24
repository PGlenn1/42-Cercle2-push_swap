#include "push_swap.h"

void	sort_three_ops(t_stack *stack, int first, int second, int third)
{
	if (first > second && second > third)
		stack->operator= SWAP;
	else if (first > third && third > second)
		stack->operator= ROT;
	else if (second > first && first > third)
		stack->operator= REV_ROT;
	else if (second > third && third > first)
		stack->operator= REV_ROT;
	else if (third > first && first > second)
		stack->operator= SWAP;
}

void	sort_three(t_root *root, t_stack *stack)
{
	while (stack->order != INCREASING)
	{
		sort_three_ops(stack, stack->first->index, stack->first->next->index,
				stack->last->index);
		stack->order = stack_is_sorted(stack);
		call_combined_ops(root);
	}
}

void	sort_five_ops(t_stack *stack_a, t_stack *stack_b, int median)
{
	if (stack_a->order != INCREASING)
	{
		if (stack_a->first->index < median)
		{
			stack_a->operator= PUSH;
		}
		else if (stack_a->size == 3)
			sort_three_ops(stack_a, stack_a->first->index,
					stack_a->first->next->index, stack_a->last->index);
		else
		{
			stack_a->operator= ROT;
		}
		if (stack_b->order != NOT_SORTED && stack_b->size > 1
			&& stack_a->operator!= PUSH)
			stack_b->operator= stack_a->operator;
	}
	else if (stack_a->order == INCREASING)
	{
		if (stack_b->order == NOT_SORTED || stack_b->size == 1)
			stack_b->operator= PUSH;
		else
			stack_b->operator= SWAP;
	}
}

void	sort_five(t_root *root)
{
	while (!final_is_sorted(root))
	{
		root->stack_a->order = stack_is_sorted(root->stack_a);
		root->stack_b->order = stack_is_sorted(root->stack_b);
		sort_five_ops(root->stack_a, root->stack_b, root->limits->limit_b);
		call_combined_ops(root);
		root->stack_a->operator= root->stack_b->operator= NOT_SET;
	}
}

op_call	rev_or_rot(t_stack *stack, int target_index, int limit)
{
	t_elem	*probe;

	probe = stack->first;
	while (probe && probe->index >= limit)
	{
		if (probe->index == target_index)
			return (ROT);
		probe = probe->next;
	}
	probe = stack->last;
	while (probe && probe->index >= limit)
	{
		if (probe->index == target_index)
			return (REV_ROT);
		probe = probe->prev;
	}
	return (NOT_SET);
}

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
		root->stack_a->operator= root->stack_b->operator= NOT_SET;
	}
}

void	sort_stacks(t_root *root)
{
	if (root->input_size == 2)
		swap_ab(root->stack_a);
	else if (root->input_size == 3)
		sort_three(root, root->stack_a);
	else if (root->input_size <= 5)
		sort_five(root);
	else if (root->input_size <= 500)
		sort_large_numbers(root);
}