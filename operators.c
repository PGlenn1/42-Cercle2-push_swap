#include "push_swap.h"

void	update_root(t_root *root)
{
	 	printf("UPDATE ROOT\n");
		root->last_a = ps_lstlast(root->first_a);
		root->sec_last_a = get_second_last(root->first_a);
		root->last_b = ps_lstlast(root->first_b);
		root->sec_last_b = get_second_last(root->first_b);
}

t_stack	*get_third_last(t_stack *stack)
{
	t_stack *probe;

	if (!stack || !stack->next || !stack->next->next)
		return (NULL);
	probe = stack;
	while (probe->next->next->next)
	{
		probe = probe->next;
	}
	// printf("THIRD LAST:%p\n", probe);
	// printf("THIRD LAST VALUE:%d\n", probe->value);
	return (probe);
}

void	push_a(t_root *root)
{
	if (!root->first_b)
		return;
	if (!root->first_a)
		root->last_a = root->first_a = root->last_b;
	else
		root->last_a->next = root->last_b;
	if (root->sec_last_b)
		root->sec_last_b->next = NULL;
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
	if (root->sec_last_a)
		root->sec_last_a->next = NULL;
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
	if (!root->first_a || !root->first_a->next)
		return ;
	tmp = NULL;
	if (root->sec_last_a)
	{
		tmp = get_third_last(root->first_a);
		tmp->next = root->last_a;
		root->last_a->next = root->sec_last_a;
		root->sec_last_a->next = NULL;
	}
	else
	{
		root->last_a->next = root->first_a;
		root->first_a->next = NULL;
		root->first_a = root->last_a;
	}
	update_root(root);
}

void	swap_b(t_root *root)	
{
	t_stack *tmp;

	printf("SWAP B\n");
	if (!root->first_b || !root->first_b->next)
		return ;
	tmp = NULL;
	if (root->sec_last_b)
	{
		tmp = get_third_last(root->first_b);
		tmp->next = root->last_b;
		root->last_b->next = root->sec_last_b;
		root->sec_last_b->next = NULL;
	}
	else
	{
		root->last_b->next = root->first_b;
		root->first_b->next = NULL;
		root->first_b = root->last_b;
	}
	update_root(root);
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
// 	last->sec_last->next = NULL;
// 	first->sec_last = last;
// 	last->next = first;
// 	last->sec_last = NULL;
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
// 	last->sec_last->next = NULL;
// 	first->sec_last = last;
// 	last->next = first;
// 	last->sec_last = NULL;
// }

// void	reverse_rotate_a(t_root *root)
// {
// 	t_stack	*first;
// 	t_stack *last;

// 	printf("REVERSE ROTATE A\n");
// 	first = root->first_a;
// 	last = ps_lstlast(root->first_a);
// 	root->first_a = first->next;
// 	first->sec_last = last;
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
// 	first->sec_last = last;
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