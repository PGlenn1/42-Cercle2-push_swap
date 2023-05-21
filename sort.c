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
		if (stack_b->order != DECREASING && stack_b->size > 1
			&& stack_a->operator!= PUSH)
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
		sort_five_ops(root->stack_a, root->stack_b, root->array[root->input_size
				/ 2]);
		call_combined_ops(root);
		print_both(root);
	}
}

void	push_segment(t_stack *from, t_stack *to, int limit, int median)
{
	if (from->first->index < limit)
	{
		push_ab(from, to);
		if (to->size > 1 && to->first->index < median)
			to->operator= ROT;
	}
	if (from->size > 1 && from->first->index >= limit)
		from->operator= ROT;
}

void	sort_hundred_ops_b(t_stack *stack_a, t_stack *stack_b, t_limits *limits)
{
	(void)stack_a, (void)stack_b, (void)limits;
}

void	sort_hundred_ops_a(t_stack *stack_a, t_stack *stack_b, t_limits *limits)
{
	printf("SORT HUNDRED OPS A\n");
	printf("stack_a->size:%d, limit_a:%d\n", stack_a->size, limits->limit_a);
	if (stack_a->size - 1 <= limits->limit_a)
	{
		printf("LIMIT A\n");
		push_segment(stack_a, stack_b, limits->limit_c, limits->median_c);
	}
	else if (stack_a->size - 1 <= limits->limit_b)
	{
		printf("LIMIT B\n");
		push_segment(stack_a, stack_b, limits->limit_b, limits->median_b);
	}
	else if (stack_a->size - 1 <= limits->limit_c)
	{
		printf("LIMIT C\n");
		push_segment(stack_a, stack_b, limits->limit_a, limits->median_a);
	}
}

// int	get_op(t_stack *stack, int index, int segment)
// {
// 	t_elem	*probe;

// 	probe = stack->first;
// 	while (probe->index > segment)
// 	{
// 	}
// }

void	sort_hundred(t_root *root)
{
	while (!final_is_sorted(root))
	{
		printf("\nSORT HUNDRED\n");
		print_both(root);
		root->stack_a->order = stack_is_sorted(root->stack_a);
		root->stack_b->order = stack_is_sorted(root->stack_b);
		if (root->stack_a->size == 1 || root->stack_a->order == INCREASING)
		{
			sort_hundred_ops_b(root->stack_a, root->stack_b, root->limits);
		}
		else
		{
			sort_hundred_ops_a(root->stack_a, root->stack_b, root->limits);
		}
		call_combined_ops(root);
		root->stack_a->operator= root->stack_b->operator= NOT_SET;
		if (root->stack_a->size == 1)
			return ;
	}
}

void	sort_stacks(t_root *root)
{
	if (root->input_size == 2)
		swap_ab(root->stack_a);
	else if (root->input_size == 3)
		sort_three(root, root->stack_a);
	else if (root->input_size <= 5)
	{
		sort_five(root);
	}
	else if (root->input_size <= 100)
	{
		sort_hundred(root);
	}
	// else if (root->input_size <= 500)
	// {
	// }
	// print_both(root);
	// call_stack_op(root->stack_a, root->stack_b, 'a');
	// stack_is_sorted(root->stack_a);
	// printf("SORTED RESULT:%d\n", root->stack_a->order);
}