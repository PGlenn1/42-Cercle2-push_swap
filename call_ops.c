#include "push_swap.h"

void	call_stack_op(t_stack *stack, t_stack *to, char ab, t_root *root)
{
	// printf("CALL STACK OP\n");
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
	else
	{
		printf("NO OPS\n");
		return ;
	}
	root->ops++;
	write(1, &ab, 1);
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
		root->ops++;
		ss(root);
	}
	else if (stack_a->operator== ROT && stack_b->operator== ROT)
	{
		ft_putstr_fd("rr\n", 1);
		root->ops++;
		rr(root);
	}
	else if (stack_a->operator== REV_ROT && stack_b->operator== REV_ROT)
	{
		ft_putstr_fd("rrr\n", 1);
		root->ops++;
		rrr(root);
	}
	else
	{
		call_stack_op(stack_a, stack_b, 'a', root);
		call_stack_op(stack_b, stack_a, 'b', root);
	}
	root->stack_a->operator= root->stack_b->operator= NOT_SET;
}