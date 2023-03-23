#include "push_swap.h"

void	update_root(t_root *root)
{
	 	printf("UPDATE ROOT\n");
		root->last_a = ps_lstlast(root->first_a);
		root->prev_a = get_prev(root->first_a);
		root->last_b = ps_lstlast(root->first_b);
		root->prev_b = get_prev(root->first_b);
}

void	push_a(t_root *root)
{
	if (!root->first_b)
		return;
	if (!root->first_a)
		root->last_a = root->first_a = root->last_b;
	else
		root->last_a->next = root->last_b;
	if (root->prev_b)
		root->prev_b->next = NULL;
	else if (!root->first_b->next)
		root->first_b = NULL;
	else
	 	root->first_b->next = NULL;
	update_root(root);
}

void	push_b(t_root *root)
{
	if (!root->first_a)
		return;
	if (!root->first_b)
		root->last_b = root->first_b = root->last_a;
	else
		root->last_b->next = root->last_a;
	if (root->prev_a)
		root->prev_a->next = NULL;
	else if (!root->first_a->next)
		root->first_a = NULL;
	else
	 	root->first_a->next = NULL;
	update_root(root);
}

void	swap_a(t_root *root)	
{
	t_stack *tmp;

	printf("SWAP A\n");
	tmp = NULL;
	if (!root->prev_a)
	{
		tmp = root->last_a;
		root->first_a = root->last_a;
		root->last_a = root->first_a;
	}
}



// void	ss(t_root *root)
// {
// 	// printf("SS\n");
// 	if (!root->first_a && !root->first_b)
// 		return ;
// 	else if (!root->first_a)
// 		swap(root->first_b, 'B');
// 	else if (!root->first_b)
// 		swap(root->first_a, 'A');
// 	else
// 	{
// 		swap(root->first_a, 'A');
// 		swap(root->first_b, 'B');
// 	}
// }

// void	rotate_a(t_root *root)
// {
// 	t_stack	*first;
// 	t_stack	*last;

// 	printf("ROTATE A\n");
// 	first = root->first_a;
// 	if (!first || !first->next)
// 	{
// 		printf("ERROR\n");
// 		return ;
// 	}
// 	last = ps_lstlast(first);
// 	root->first_a = last;
// 	last->prev->next = NULL;
// 	first->prev = last;
// 	last->next = first;
// 	last->prev = NULL;
// 	print_node(first);
// 	print_node(last);

// }

// void	rotate_b(t_root *root)
// {
// 	t_stack	*first;
// 	t_stack	*last;

// 	printf("ROTATE B\n");
// 	first = root->first_b;
// 	if (!first || !first->next)
// 	{
// 		printf("ERROR\n");
// 		return ;
// 	}
// 	last = ps_lstlast(first);
// 	root->first_b = last;
// 	last->prev->next = NULL;
// 	first->prev = last;
// 	last->next = first;
// 	last->prev = NULL;
// }

// void	reverse_rotate_a(t_root *root)
// {
// 	t_stack	*first;
// 	t_stack *last;

// 	printf("REVERSE ROTATE A\n");
// 	first = root->first_a;
// 	last = ps_lstlast(root->first_a);
// 	root->first_a = first->next;
// 	first->prev = last;
// 	first->next = NULL;
// 	last->next = first;
// }

// void	reverse_rotate_b(t_root *root)
// {
// 	t_stack	*first;
// 	t_stack *last;

// 	printf("REVERSE ROTATE B\n");
// 	first = root->first_b;
// 	last = ps_lstlast(root->first_b);
// 	root->first_b = first->next;
// 	first->prev = last;
// 	first->next = NULL;
// 	last->next = first;

// 	print_node(first);
// 	print_node(last);
// }

// void	rr(t_root *root)
// {
// 	printf("RR\n");
// 	if (!root->first_a && !root->first_b)
// 	{
// 		printf("ERROR\n");
// 		return ;
// 	}
// 	else if (!root->first_a)
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
// 	if (!root->first_a && !root->first_b)
// 	{
// 		printf("ERROR\n");
// 		return ;
// 	}
// 	else if (!root->first_a)
// 		reverse_rotate_b(root);
// 	else if (!root->first_b)
// 		reverse_rotate_a(root);
// 	else
// 	{
// 		reverse_rotate_a(root);
// 		reverse_rotate_b(root);
// 	}

// }