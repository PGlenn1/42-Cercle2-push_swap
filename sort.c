#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	printf("SORT THREE\n");
	first = stack->first->value;
	third = stack->last->value;
	second = stack->last->prev->value;
	printf("PATH ");
	if (first > second && second > third)
	{
		// first > second > third
		// 3 2 1
		printf("A\n");
		stack->operator= SWAP;
		// swap_ab(stack);
		// rev_rotate_ab(stack);
	}
	else if (first > third && third > second)
	{
		// first > third > second
		// 3 1 2
		printf("B\n");
		stack->operator= ROT;
		// rev_rotate_ab(stack);
	}
	else if (second > first && first > third)
	{
		// second > first > third
		// 2 3 1
		printf("C\n");
		stack->operator= REV_ROT;
		// rotate_ab(stack);
	}
	else if (second > third && third > first)
	{
		// second > third > first
		// 1 3 2
		printf("D\n");
		stack->operator= SWAP;
		// swap_ab(stack);
	}
	else if (third > first && first > second)
	{
		// third > first > second
		// 2 1 3
		printf("E\n");
		stack->operator= SWAP;
		// rev_rotate_ab(stack);
		// swap_ab(stack);
	}
	else
	{
		printf("Z\n");
		ft_error(UNWANTED_BEHAVIOR);
	}
}

// void	sort_five(t_root *root)
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

void	algo_sort_a(t_stack *stack)
{
	printf("ALGO SORT A\n");
	if (stack->size < 2)
	{
		ft_error(UNWANTED_BEHAVIOR);
	}
	else if (stack->size == 2)
	{
		stack->operator= SWAP;
	}
	else if (stack->size == 3)
	{
		sort_three(stack);
	}
	else if (stack->size <= 5)
	{
	}
}

void	sort_stacks(t_root *root)
{
	printf("SORT STACKS\n");

	if (root->stack_a->order != INCREASING)
		algo_sort_a(root->stack_a);
	// if (root->stack_b->order != DECREASING)
	// 	algo_sort_a(root->stack_b);
	call_stack_op(root->stack_a, root->stack_b, 'a');
	is_sorted(root->stack_a);
	// print_result(root->stack_a);
	(void)root;
}