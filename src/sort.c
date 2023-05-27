#include "../includes/push_swap.h"

void	sort_five_ops(t_stack *stack_a, t_stack *stack_b, int median)
{
	if (stack_a->order != INCREASING)
	{
		if (stack_a->first->index < median)
			stack_a->operator= PUSH;
		else if (stack_a->size == 3)
			sort_three_ops(stack_a, stack_a->first->index,
					stack_a->first->next->index, stack_a->last->index);
		else
			stack_a->operator= ROT;
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

void	sort_stacks(t_root *root)
{
	if (root->input_size == 2)
		swap_ab(root->stack_a, 0);
	else if (root->input_size == 3)
		sort_three(root, root->stack_a);
	else if (root->input_size <= 5)
		sort_five(root);
	else if (root->input_size <= 500)
		sort_large_numbers(root);
}
