#include "../includes/push_swap.h"

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
