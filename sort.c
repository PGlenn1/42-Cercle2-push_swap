#include "push_swap.h"

void	sort_three_a(t_stack *stack)
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
		stack->operator= REV_ROT;
	}
	else if (first > third && third > second)
	{
		// first > third > second
		// 3 1 2
		printf("B\n");
		stack->operator= ROT;
	}
	else if (second > first && first > third)
	{
		// second > first > third
		// 2 3 1
		printf("C\n");
		stack->operator= REV_ROT;
	}
	else if (second > third && third > first)
	{
		// second > third > first
		// 1 3 2
		printf("D\n");
		stack->operator= REV_ROT;
	}
	else if (third > first && first > second)
	{
		// third > first > second
		// 2 1 3
		printf("E\n");
		stack->operator= SWAP;
	}
	else
	{
		printf("F\n");
		ft_error(UNWANTED_BEHAVIOR);
	}
}

void	sort_three_b(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->first->value;
	third = stack->last->value;
	second = stack->last->prev->value;
	if (first < second && second < third)
	{
		printf("A\n");
		// 1 2 3
		stack->operator= ROT;
	}
	else if (first < third && third < second)
	{
		printf("B\n");
		// 1 3 2
		stack->operator= ROT;
	}
	else if (second < first && first < third)
	{
		printf("C\n");
		// 2 1 3
		stack->operator= REV_ROT;
	}
	else if (second < third && third < first)
	{
		printf("D\n");
		// 3 1 2
		stack->operator= ROT;
	}
	else if (third < first && first < second)
	{
		printf("D\n");
		// 2 3 1
		stack->operator= SWAP;
	}
	else
		ft_error(UNWANTED_BEHAVIOR);
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

void	sort_stacks(t_root *root)
{
	if (root->stack_size == 2)
	{
		swap_ab(root->stack_a);
	}
	else if (root->stack_size == 3)
	{
		sort_three_a(root->stack_a);
	}
	else if (root->stack_size <= 5)
	{
		sort_five(root);
	}
	else if (root->stack_size <= 100)
	{
	}
	else if (root->stack_size <= 500)
	{
	}
	call_stack_op(root->stack_a, root->stack_b, 'a');
	is_sorted(root->stack_a);
	printf("SORTED RESULT:%d\n", root->stack_a->order);
}