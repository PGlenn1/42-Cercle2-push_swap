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
		printf("SORT FIVE\n");
		// print_array(root->array, root->input_size);
		root->stack_a->order = stack_is_sorted(root->stack_a);
		root->stack_b->order = stack_is_sorted(root->stack_b);
		sort_five_ops(root->stack_a, root->stack_b, root->array[root->input_size
				/ 2]);
		call_combined_ops(root);
		print_both(root);
	}
}

op_call	rev_or_rot(t_stack *stack, int target_index, int limit)
{
	t_elem	*probe;

	printf("REV OR ROT\n");
	probe = stack->first;
	while (probe && probe->index >= limit)
	{
		// printf("while probe->index:%d\n", probe->index);
		if (probe->index == target_index)
		{
			printf("ROT FOUND\n");
			return (ROT);
		}
		probe = probe->next;
	}
	printf("DEBUG probe->index:%d\n", probe->index);
	probe = stack->last;
	while (probe && probe->index >= limit)
	{
		// printf("while probe->index:%d\n", probe->index);
		if (probe->index == target_index)
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
	// printf("SAUGHT INDEX:%d || ACTUAL INDEX:%d\nMEDIAN:%d\nLIMIT:%d\n",
	// index,
	// stack->first->index, median, limit);
	if (index >= median)
		return (rev_or_rot(stack, index, median));
	else
		return (rev_or_rot(stack, index, limit));
}

void	sort_large_numbers_ops_b(t_stack *stack_a, t_stack *stack_b,
		t_limits *limits, int target_index)
{
	printf("SORT HUNDRED OPS B\n");
	printf("A_INDEX:%d\n", stack_a->first->index);
	printf("B_INDEX:%d\n", stack_b->first->index);
	if (stack_b->first->index == target_index)
	{
		printf("INDEX = TARGET\n");
		push_ab(stack_b, stack_a);
	}
	else if (target_index <= limits->limit_a)
	{
		printf("MEDIAN A\n");
		stack_b->operator= find_index(stack_b, target_index, limits->median_a,
				0);
	}
	else if (target_index <= limits->limit_b)
	{
		printf("MEDIAN B\n");
		stack_b->operator= find_index(stack_b, target_index, limits->median_b,
				limits->limit_a);
	}
	else if (target_index <= limits->limit_c)
	{
		printf("MEDIAN C\n");
		stack_b->operator= find_index(stack_b, target_index, limits->median_c,
				limits->limit_b);
	}
	else if (target_index <= limits->limit_d)
	{
		printf("MEDIAN D\n");
		stack_b->operator= find_index(stack_b, target_index, limits->median_d,
				limits->limit_c);
	}
	else
		ft_error(UNWANTED_BEHAVIOR);
}

void	push_segment(t_stack *from, t_stack *to, int limit, int median)
{
	// printf("INDEX:%d\n", from->first->index);
	// printf("LIMIT = %d\n", limit);
	// printf("MEDIAN = %d\n", median);
	// if (limit == 75 && from->first->index == 74)
	// 	ft_error(UNWANTED_BEHAVIOR);
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
	printf("SORT HUNDRED OPS A\n");
	if (stack_a->first->index == limits->limit_d - 1)
	{
		printf("FIRST = LAST\n");
		stack_a->operator= ROT;
	}
	else if (stack_b->size > limits->limit_c)
	{
		printf("LIMIT D\n");
		push_segment(stack_a, stack_b, limits->limit_d, limits->median_d);
	}
	else if (stack_b->size > limits->limit_b)
	{
		printf("LIMIT C\n");
		// ft_error(UNWANTED_BEHAVIOR);
		push_segment(stack_a, stack_b, limits->limit_c, limits->median_c);
	}
	else if (stack_b->size > limits->limit_a)
	{
		printf("LIMIT B\n");
		// ft_error(UNWANTED_BEHAVIOR);
		push_segment(stack_a, stack_b, limits->limit_b, limits->median_b);
	}
	else if (stack_b->size >= 0)
	{
		printf("LIMIT A\n");
		push_segment(stack_a, stack_b, limits->limit_a, limits->median_a);
	}
	else
		ft_error(UNWANTED_BEHAVIOR);
}

void	optimize(t_root *root, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 && stack_a->first->index
		- 1 == stack_a->first->next->index)
	{
		// print_both(root);
		// ft_error(UNWANTED_BEHAVIOR);
		stack_a->operator= SWAP;
		root->opti++;
	}
	call_combined_ops(root);
	root->stack_a->operator= root->stack_b->operator= NOT_SET;
	(void)stack_b;
}

void	sort_large_numbers(t_root *root)
{
	while (!final_is_sorted(root))
	{
		printf("\nSORT HUNDRED\n");
		// print_both(root);
		root->stack_a->order = stack_is_sorted(root->stack_a);
		optimize(root, root->stack_a, root->stack_b);
		if ((root->stack_a->size == 1 || root->stack_a->order == INCREASING)
			&& root->stack_a->last->index == root->limits->limit_d - 1)
		{
			printf("DEBUG 1\n");
			sort_large_numbers_ops_b(root->stack_a, root->stack_b, root->limits,
					root->stack_a->first->index - 1);
		}
		else
		{
			printf("DEBUG 2\n");
			sort_large_numbers_ops_a(root->stack_a, root->stack_b,
					root->limits);
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
	else if (root->input_size <= 500)
	{
		sort_large_numbers(root);
	}
}