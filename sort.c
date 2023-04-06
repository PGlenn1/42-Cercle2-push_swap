#include "push_swap.h"

void	median_five(t_stack *stack)
{
	int		i;
	int		*array;
	t_elem	*probe;

	array = malloc(sizeof(int) * stack->size);
	if (!array)
		ft_error(MALLOC_FAIL);
	probe = stack->first;
	i = 0;
	while (probe)
	{
		array[i] = probe->value;
		probe = probe->next;
		i++;
	}
	array = bubble_sort(array, 5);
	stack->median = array[2];
	printf("FOUND MEDIAN:%d\n", stack->median);
	free(array);
}

void	get_median(t_stack *stack)
{
	int	first;
	int	middle;
	int	last;

	if (!stack || !stack->first)
		return ;
	(void)middle;
	first = stack->first->value;
	last = stack->first->value;
	(void)last;
	(void)first;
	if (stack->size <= 12)
		median_five(stack);
	// else if
	//     median = median_twelve(stack);
	// else
	//     median = median(stack);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	sec_last;
	int	last;

	printf("SORT THREE\n");
	first = stack->first->value;
	last = stack->last->value;
	sec_last = stack->last->prev->value;
	printf("PATH ");
	// print_result(stack);
	if (first < sec_last && sec_last < last)
	{
		// first < sec_last < last
		// 2 4 6
		printf("A\n");
		// rotate_ab(stack);
		stack->operator= ROT;
		// swap_ab(stack);
	}
	else if (first < last && last < sec_last)
	{
		// first < last < sec_last
		// 1 8 5
		printf("B\n");
		stack->operator= REV_ROT;
		// rev_rotate_ab(stack);
	}
	else if (sec_last < first && first < last)
	{
		// sec_last < first < last
		// 7 3 9
		printf("C\n");
		stack->operator= ROT;
		// rotate_ab(stack);
	}
	else if (sec_last < last && last < first)
	{
		// sec_last < last < first
		// 20 15 18
		printf("D\n");
		stack->operator= SWAP;
		swap_ab(stack);
	}
	else if (last < first && first < sec_last)
	{
		// last < first < sec_last
		// 5 6 4
		printf("E\n");
		stack->operator= REV_ROT;
		// rev_rotate_ab(stack);
		// swap_ab(stack);
	}
	else
	{
		ft_error(UNWANTED_BEHAVIOR);
	}
}

// void	sort_five(t_stack *stack_a, t_stack *stack_b)
// {
// }

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	printf("SORT FIVE\n");
	get_median(stack_a);
	if (stack_a->size > 3)
	{
		if (stack_a->last->value < stack_a->median)
			stack_a->operator= PUSH;
		else
			stack_a->operator= ROT;
	}
	else if (is_sorted(stack_b))
		stack_b->operator= ROT;
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	push_ab(stack_b, stack_a);
	push_ab(stack_b, stack_a);
}

// void	optimize(t_root *root)
// {
// }

void	call_stack_op(t_stack *stack, t_stack *to, char ab)
{
	if (stack->operator== SWAP)
	{
		swap_ab(stack);
		write(1, "s", 1);
	}
	else if (stack->operator== PUSH)
	{
		push_ab(stack, to);
		write(1, "p", 1);
	}
	else if (stack->operator== ROT)
	{
		rotate_ab(stack);
		write(1, "r", 1);
	}
	else if (stack->operator== REV_ROT)
	{
		rev_rotate_ab(stack);
		ft_putstr_fd("rr", 1);
	}
	write(1, &ab, 1);
	write(1, "\n", 1);
}

void	call_combined_ops(t_root *root)
{
	if (root->stack_a->operator== SWAP && root->stack_b->operator== SWAP)
	{
		ft_putstr_fd("ss\n", 1);
		ss(root);
	}
	else if (root->stack_a->operator== ROT && root->stack_b->operator== ROT)
	{
		ft_putstr_fd("rr\n", 1);
		rr(root);
	}
	else if (root->stack_a->operator== REV_ROT
			&& root->stack_b->operator== REV_ROT)
	{
		ft_putstr_fd("rrr\n", 1);
		rrr(root);
	}
}

void	exec_ops(t_root *root)
{
	if (root->stack_a->operator== root->stack_b->operator)
		call_combined_ops(root);
	else
	{
		call_stack_op(root->stack_a, root->stack_b, 'a');
		call_stack_op(root->stack_b, root->stack_a, 'b');
	}
	root->stack_a->operator= NOT_SET;
	root->stack_b->operator= NOT_SET;
	root->ops++;
}

void	calc_execution_a(t_root *root, t_stack *stack)
{
	///// THIS IS WHERE THE MAGIC HAPPENS.
	is_sorted(stack);
	if (stack->size == 3)
	{
		sort_three(root->stack_a);
	}
	else if (stack->size >= 4)
	{
		if ()
	}
}

void	op_calls(t_root *root)
{
	calc_execution_a(root, root->stack_a);
	calc_execution_b(root, root->stack_b);
	// optimize(root);
	exec_ops(root);
}

void	pick_algo(t_root *root) /// LAST MUST BE SMALLEST
{
	printf("PICK ALGO\n");
	if (root->stack_a->size < 2)
	{
		ft_error(UNWANTED_BEHAVIOR);
	}
	else if (root->stack_a->size == 2)
	{
		swap_ab(root->stack_a);
		root->ops++;
		return ;
	}
	else if (root->stack_a->size == 3)
	{
		sort_three(root->stack_a);
		root->ops++;
		return ;
	}
	else
	{
		printf("SIZE 5 DEBUG\n");
		while (root->stack_a->order != DECREASING)
		{
			printf("TEST\n");
			op_calls(root);
		}
	}
}