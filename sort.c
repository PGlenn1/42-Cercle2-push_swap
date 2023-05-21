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
	printf("INDEX:%d\n", from->first->index);
	printf("LIMIT = %d\n", limit);
	printf("MEDIAN = %d\n", median);
	if (from->first->index <= limit)
	{
		push_ab(from, to);
		if (to->size > 1 && to->first->index < median)
			to->operator= ROT;
	}
	if (from->size > 1 && from->first->index >= limit)
		from->operator= ROT;
}

op_call	ind_over_median(t_stack *stack, int index, int median)
{
	t_elem	*probe;

	printf("OVER MED\n");
	probe = stack->first;
	printf("1 probe->index:%d|probe->value:%d\n", probe->index, probe->value);
	while (probe && probe->index >= median)
	{
		printf("while probe->index:%d|probe->value:%d\n", probe->index,
				probe->value);
		if (probe->index == index)
		{
			printf("ROT FOUND\n");
			return (ROT);
		}
		probe = probe->next;
	}
	printf("debug probe->index:%d|probe->value:%d\n", probe->index,
			probe->value);
	probe = stack->last;
	while (probe && probe->index >= median)
	{
		printf("while probe->index:%d|probe->value:%d\n", probe->index,
				probe->value);
		if (probe->index == index)
		{
			printf("REV ROT FOUND\n");
			return (REV_ROT);
		}
		probe = probe->prev;
	}
	ft_error(UNWANTED_BEHAVIOR);
	return (NOT_SET);
}

op_call	ind_under_median(t_stack *stack, int index, int limit)
{
	t_elem	*probe;

	printf("UNDER MED\n");
	probe = stack->first;
	while (probe && probe->index >= limit)
	{
		printf("WHILE UNDER\n");
		if (probe->index == index)
		{
			printf("ROT FOUND\n");
			return (ROT);
		}
		probe = probe->next;
	}
	probe = stack->last;
	while (probe && probe->index >= limit)
	{
		printf("WHILE UNDER\n");
		if (probe->index == index)
		{
			printf("REV ROT FOUND\n");
			return (REV_ROT);
		}
		probe = probe->prev;
	}
	ft_error(UNWANTED_BEHAVIOR);
	return (NOT_SET);
}

op_call	find_index(t_stack *stack, int index, int median, int limit)
{
	(void)limit;
	printf("INDEX:%d\nMEDIAN:%d\n", index, median);
	if (index >= median)
		return (ind_over_median(stack, index, median));
	else
		return (ind_under_median(stack, index, limit));
}

void	sort_hundred_ops_b(t_stack *stack_a, t_stack *stack_b, t_limits *limits)
{
	printf("SORT HUNDRED OPS B\n");
	printf("A_INDEX:%d\n", stack_a->first->index);
	printf("B_INDEX:%d\n", stack_b->first->index);
	if (stack_b->first->index == stack_a->first->index - 1)
	{
		push_ab(stack_b, stack_a);
	}
	else if (stack_b->size - 1 <= limits->limit_a)
	{
		printf("MEDIAN A\n");
		stack_b->operator= find_index(stack_b, stack_a->first->index - 1,
				limits->median_a, 0);
	}
	else if (stack_b->size - 1 <= limits->limit_b)
	{
		printf("MEDIAN B\n");
		stack_b->operator= find_index(stack_b, stack_a->first->index - 1,
				limits->median_b, limits->limit_a);
	}
	else if (stack_b->size - 1 <= limits->limit_c)
	{
		printf("MEDIAN C\n");
		stack_b->operator= find_index(stack_b, stack_a->first->index - 1,
				limits->median_c, limits->limit_b);
	}
}

void	sort_hundred_ops_a(t_stack *stack_a, t_stack *stack_b, t_limits *limits)
{
	printf("SORT HUNDRED OPS A\n");
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
		// if (stack_a->first->index == limits->limit_c)
		// 	ft_error(UNWANTED_BEHAVIOR);
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
			printf("DEBUG 1\n");
			sort_hundred_ops_b(root->stack_a, root->stack_b, root->limits);
		}
		else
		{
			printf("DEBUG 2\n");
			sort_hundred_ops_a(root->stack_a, root->stack_b, root->limits);
		}
		call_combined_ops(root);
		root->stack_a->operator= root->stack_b->operator= NOT_SET;
		// if (root->stack_a->size == 1)
		// 	return ;
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