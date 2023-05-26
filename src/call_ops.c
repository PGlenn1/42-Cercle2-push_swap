#include "../includes/push_swap.h"

void	call_stack_op(t_stack *stack, t_stack *to)
{
	if (stack->operator== SWAP)
		swap_ab(stack, 0);
	else if (stack->operator== ROT)
		rotate_ab(stack, 0);
	else if (stack->operator== PUSH)
		push_ab(stack, to);
	else if (stack->operator== REV_ROT)
		rev_rotate_ab(stack, 0);
}

void	call_combined_ops(t_root *root)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = root->stack_a;
	stack_b = root->stack_b;
	if (stack_a->operator== SWAP && stack_b->operator== SWAP)
		ss(root);
	else if (stack_a->operator== ROT && stack_b->operator== ROT)
		rr(root);
	else if (stack_a->operator== REV_ROT && stack_b->operator== REV_ROT)
		rrr(root);
	else
	{
		call_stack_op(stack_a, stack_b);
		call_stack_op(stack_b, stack_a);
	}
	stack_a->operator= stack_b->operator= NOT_SET;
}
