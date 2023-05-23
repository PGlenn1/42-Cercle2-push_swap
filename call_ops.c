#include "push_swap.h"

void	call_stack_op(t_stack *stack, t_stack *to, t_root *root)
{
	// printf("CALL STACK OP\n");
	if (stack->operator== SWAP)
	{
		swap_ab(stack);
		write(1, "s", 1);
	}
	else if (stack->operator== ROT)
	{
		rotate_ab(stack);
		write(1, "r", 1);
	}
	else if (stack->operator== PUSH)
	{
		push_ab(stack, to);
		write(1, "p", 1);
	}
	else if (stack->operator== REV_ROT)
	{
		rev_rotate_ab(stack);
		ft_putstr_fd("rr", 1);
	}
	else
	{
		printf("%c->NO OPS\n", stack->ab);
		return ;
	}
	root->ops++;
	write(1, &stack->ab, 1);
	write(1, "\n", 1);
}

void	call_combined_ops(t_root *root)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = root->stack_a;
	stack_b = root->stack_b;
	if (stack_a->operator== SWAP && stack_b->operator== SWAP)
	{
		ft_putstr_fd("ss\n", 1);
		ss(root);
	}
	else if (stack_a->operator== ROT && stack_b->operator== ROT)
	{
		ft_putstr_fd("rr\n", 1);
		rr(root);
	}
	else if (stack_a->operator== REV_ROT && stack_b->operator== REV_ROT)
	{
		ft_putstr_fd("rrr\n", 1);
		rrr(root);
	}
	else
	{
		call_stack_op(stack_a, stack_b, root);
		call_stack_op(stack_b, stack_a, root);
		return ;
	}
	root->ops++;
}