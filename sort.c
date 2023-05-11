#include "push_swap.h"

void	sort_three_ops(t_stack *stack, int first, int second, int third)
{
	printf("SORT THREE OPS\n");
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
	else
	{
		printf("ERROR SORT THREE\n");
		print_result(stack);
		ft_error(UNWANTED_BEHAVIOR);
	}
}

void	sort_three(t_root *root, t_stack *stack)
{
	while (stack->order != INCREASING)
	{
		sort_three_ops(stack, stack->first->value, stack->first->next->value,
				stack->last->value);
		stack->order = stack_is_sorted(stack);
		call_combined_ops(root);
	}
}

// int	find_remaining_values(t_stack *stack, int median)
// {
// t_elem	*probe;
//
// probe = stack->first;
// while (probe)
// {
// if (probe->value < median)
// return (1);
// probe = probe->next;
// }
// return (0);
// }
void	sort_five_ops(t_stack *stack_a, t_stack *stack_b, int median)
{
	if (stack_a->order != INCREASING)
	{
		if (stack_a->first->value < median)
			stack_a->operator= PUSH;
		else if (stack_a->size == 3)
			sort_three_ops(stack_a, stack_a->first->value,
					stack_a->first->next->value, stack_a->last->value);
		else
			stack_a->operator= ROT;
		if (stack_b->order != DECREASING && stack_b->size > 1)
			stack_b->operator= stack_a->operator;
	}
	else if (stack_a->order == INCREASING)
	{
		if (stack_b->order == DECREASING || stack_b->size == 1)
			stack_b->operator= PUSH;
		else
			stack_b->operator= SWAP;
	}
}

void	sort_five(t_root *root)
{
	while (!final_is_sorted(root))
	{
		// print_array(root->array, root->input_size);
		root->stack_a->order = stack_is_sorted(root->stack_a);
		root->stack_b->order = stack_is_sorted(root->stack_b);
		sort_five_ops(root->stack_a, root->stack_b, root->array[2]);
		call_combined_ops(root);
		print_both(root);
	}
}

void	sort_hundred(t_stack *stack_a, t_stack *stack_b)
{
	int	a_target;

	(void)stack_b;
	a_target = stack_a->size / 3;
	printf("a_target=%d\n", a_target);
	ft_error(UNWANTED_BEHAVIOR);
}

void	sort_stacks(t_root *root)
{
	if (root->input_size == 2)
		swap_ab(root->stack_a);
	else if (root->input_size == 3)
		sort_three(root, root->stack_a);
	else if (root->input_size <= 5)
		sort_five(root);
	else if (root->input_size <= 100)
		sort_hundred(root->stack_a, root->stack_b);
	else if (root->input_size <= 500)
	{
	}
	// print_both(root);
	// call_stack_op(root->stack_a, root->stack_b, 'a');
	// stack_is_sorted(root->stack_a);
	// printf("SORTED RESULT:%d\n", root->stack_a->order);
}