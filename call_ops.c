#include "push_swap.h"

void	call_stack_op(t_stack *stack, t_stack *to, t_root *root)
{
	if (stack->operator== SWAP)
		swap_ab(stack);
	else if (stack->operator== ROT)
		rotate_ab(stack);
	else if (stack->operator== PUSH)
		push_ab(stack, to);
	else if (stack->operator== REV_ROT)
		rev_rotate_ab(stack);
	// else
	// {
	// 	printf("%c->NO OPS\n", stack->ab);
	// 	return ;
	// }
	root->ops++;
}

void	call_combined_ops(t_root *root)
{
	t_stack *stack_a;
	t_stack *stack_b;

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
		call_stack_op(stack_a, stack_b, root);
		call_stack_op(stack_b, stack_a, root);
		return ;
	}
	root->ops++;
}