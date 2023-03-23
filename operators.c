#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	if (!from || !to)
		ft_error(PTR_ERROR);
	if (!from->first)
		return ;
	if (!to->first)
		to->first = from->last;
	else
		to->last->next = from->last;
	if (from->sec_last)
		from->sec_last->next = NULL;
	else if (from->first->next)
		from->first->next = NULL;
	else
		from->first = NULL;
}


void	push_ab(t_root *root, stack_ab ab)
{
	if (ab == A)
	{
		printf("PUSH A\n");
		push(root->stack_b, root->stack_a);
	}
	else
	{	
		printf("PUSH B\n");
		push(root->stack_a, root->stack_b);
	}
	update_stack_ptrs(root);
}

void	swap(t_root *root, t_stack *stack)
{
	if (!stack->first || !stack->first->next)
		ft_error(PTR_ERROR);
	if (stack->sec_last)
	{
		stack->thi_last->next = stack->last;
		stack->last->next = stack->sec_last;
		stack->sec_last->next = NULL;
	}
	else
	{
		stack->last->next = stack->first;
		stack->first->next = NULL;
		stack->first = stack->last;
	}
	update_stack_ptrs(root);
}

void	swap_ab(t_root *root, stack_ab ab)	
{
	t_stack *stack;

	if (ab == A)
	{
		if (!root->stack_a)
			return ;
		printf("SWAP A\n");
		stack = root->stack_a;
	}
	else
	{
		if (!root->stack_b)
			return ;
		printf("SWAP B\n");
		stack = root->stack_b;
	}
	swap(root, stack);
}

void	ss(t_root *root)
{
	printf("SS\n");
	if (!root->stack_a || !root->stack_b)
		return ;
	else
	{
		swap_ab(root, A);
		swap_ab(root, B);
	}
}

// void	rotate_a(t_root *root)
// {
// 	t_elem *tmp;
	
// 	printf("ROTATE A\n");
// 	tmp = NULL;
// 	if (!root->first || !root->first->next)
// 	{
// 		printf("STACK A TOO SMALL\n");
// 		return ;
// 	}
// 	if (root->sec_last)
// 	{
// 		tmp = root->first;
// 		root->first = root->last;
// 		root->first->next = tmp;
// 		root->sec_last->next = NULL;
// 	}
// 	else
// 	{
// 		printf("INTO\n");
// 		swap_a(root);
// 	}
// }

// void	rotate_b(t_root *root)
// {
// 	t_elem *tmp;
	
// 	printf("ROTATE B\n");
// 	tmp = NULL;
// 	if (!root->first || !root->first->next)
// 	{
// 		printf("ERROR STACK B TOO SMALL\n");
// 		return ;
// 	}
// 	if (root->sec_last)
// 	{
// 		tmp = root->first;
// 		root->first = root->last;
// 		root->first->next = tmp;
// 		root->sec_last->next = NULL;
// 	}
// 	else
// 	{
// 		printf("INTO\n");
// 		swap_b(root);
// 	}
// }

// void	reverse_rotate_a(t_root *root)
// {
// 	t_elem	*first;
// 	t_elem *last;

// 	printf("REVERSE ROTATE A\n");
// 	first = root->first;
// 	last = ps_lstlast(root->first);
// 	root->first = first->next;
// 	first->sec_last = last;
// 	first->next = NULL;
// 	last->next = first;
// }

// void	reverse_rotate_b(t_root *root)
// {
// 	t_elem	*first;
// 	t_elem *last;

// 	printf("REVERSE ROTATE B\n");
// 	first = root->first;
// 	last = ps_lstlast(root->first);
// 	root->first = first->next;
// 	first->sec_last = last;
// 	first->next = NULL;
// 	last->next = first;

// 	print_node(first);
// 	print_node(last);
// }

// void	rr(t_root *root)
// {
// 	printf("RR\n");
// 	if (!root->first && !root->first)
// 	{
// 		printf("ERROR\n");
// 		return ;
// 	}
// 	else if (!root->first)
// 		rotate_b(root);
// 	else if (!root)
// 		rotate_a(root);
// 	else
// 	{
// 		rotate_a(root);
// 		rotate_b(root);
// 	}
// }

// void	rrr(t_root *root)
// {
// 	printf("RRR\n");
// 	if (!root->first && !root->first)
// 	{
// 		printf("ERROR\n");
// 		return ;
// 	}
// 	else if (!root->first)
// 		reverse_rotate_b(root);
// 	else if (!root->first)
// 		reverse_rotate_a(root);
// 	else
// 	{
// 		reverse_rotate_a(root);
// 		reverse_rotate_b(root);
// 	}

// }