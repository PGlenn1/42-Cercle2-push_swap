#include "push_swap.h"

void	push(t_root *root, stack_ab ab)
{
	if (ab == A)
	{
		printf("PUSH A\n");
	}
}

// void	swap_a(t_root *root)	
// {
// 	t_elem *tmp;

// 	printf("SWAP A\n");
// 	if (!root->first || !root->first->next)
// 		return ;
// 	tmp = NULL;
// 	if (root->sec_last)
// 	{
// 		tmp = get_third_last(root->first);
// 		tmp->next = root->last;
// 		root->last->next = root->sec_last;
// 		root->sec_last->next = NULL;
// 	}
// 	else
// 	{
// 		root->last->next = root->first;
// 		root->first->next = NULL;
// 		root->first = root->last;
// 	}
// 	update_root(root);
// }

void	swap(t_root *root, stack_ab ab)	
{
	t_stack *stack;

	if (ab == A)
	{
		printf("SWAP A\n");
		stack = root->stack_a;
	}
	else
	{
		printf("SWAP B\n");
		stack = root->stack_b;
	}
	if (!stack->first || !stack->first->next)
		return ;
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
	update_stacks(root);
}

// void	ss(t_root *root)
// {
// 	printf("SS\n");
// 	if (!root->first && !root->first)
// 		return ;
// 	else if (!root->first)
// 		swap_b(root);
// 	else if (!root->first)
// 		swap_a(root);
// 	else
// 	{
// 		swap_a(root);
// 		swap_b(root);
// 	}
// }

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