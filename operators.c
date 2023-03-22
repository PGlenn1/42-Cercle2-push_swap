#include "push_swap.h"

void	push_a(t_root *root)
{
	t_stack	*last_a;
	t_stack	*last_b;

	// printf("PUSH A\n");
	if (!root->stack_b)
		return ;
	last_a = ps_lstlast(root->stack_a);
	last_b = ps_lstlast(root->stack_b);

	if (last_b->prev)
		last_b->prev->next = NULL;
	else
		root->stack_b = NULL;
	if (last_a)
	{
		last_a->next = last_b;
		last_b->prev = last_a;
	}
	else
	{
		root->stack_a = last_b;
		last_b->next = NULL;
		last_b->prev = NULL;
	}
}

void	push_b(t_root *root)
{
	t_stack	*last_a;
	t_stack	*last_b;

	// printf("PUSH B\n");
	if (!root->stack_a) // Check if stack_a is empty
		return ;
	last_a = ps_lstlast(root->stack_a);
	last_b = ps_lstlast(root->stack_b);
	if (last_a->prev)
		last_a->prev->next = NULL;
	else
		root->stack_a = NULL;
	if (last_b)
	{
		last_b->next = last_a;
		last_a->prev = last_b;
	}
	else
	{
		root->stack_b = last_a;
		last_a->next = NULL;
		last_a->prev = NULL;
	}
}

void	swap_nodes(t_stack *node_a, t_stack *node_b)
{
	t_stack	*tmp;

	// printf("swapping...\n");
	if (!node_a || !node_b)
		return ;
	tmp = node_a->prev;
	if (node_a->prev)
		node_a->prev->next = node_b;
	node_a->next = node_b->next;
	node_a->prev = node_b;
	node_b->next = node_a;
	node_b->prev = tmp;
}

void	swap_a(t_stack *stack)
{
	t_stack	*last;

	// printf("\nSWAP A\n");
	if (!stack)
		return ;
	last = ps_lstlast(stack);
	if (!stack->next)
		return ;
	swap_nodes(last->prev, last);
	last = ps_lstlast(stack);
}

void	swap_b(t_stack *stack)
{
	t_stack	*last;
	t_stack	*prev;

	last = ps_lstlast(stack);
	if (!last->next)
		return ;
	prev = ps_lstprev(stack);
	last->next = prev->next;
	prev->next = NULL;
}

void	ss(t_root *root)
{
	// printf("SS\n");
	if (!root->stack_a && !root->stack_b)
		return ;
	else if (!root->stack_a)
		swap_b(root->stack_b);
	else if (!root->stack_b)
		swap_a(root->stack_a);
	else
	{
		swap_a(root->stack_a);
		swap_b(root->stack_a);
	}
}

void	rotate_a(t_root *root)
{
	t_stack	*first;
	t_stack	*last;

	printf("ROTATE A\n");
	first = root->stack_a;
	if (!first || !first->next)
	{
		printf("ERROR\n");
		return ;
	}
	last = ps_lstlast(first);
	root->stack_a = last;
	last->prev->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	print_node(first);
	print_node(last);

}

void	rotate_b(t_root *root)
{
	t_stack	*first;
	t_stack	*last;

	printf("ROTATE B\n");
	first = root->stack_b;
	if (!first || !first->next)
	{
		printf("ERROR\n");
		return ;
	}
	last = ps_lstlast(first);
	root->stack_b = last;
	last->prev->next = NULL;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
}

void	reverse_rotate_a(t_root *root)
{
	t_stack	*first;
	t_stack *last;

	printf("REVERSE ROTATE A\n");
	first = root->stack_a;
	last = ps_lstlast(root->stack_a);
	root->stack_a = first->next;
	first->prev = last;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate_b(t_root *root)
{
	t_stack	*first;
	t_stack *last;

	printf("REVERSE ROTATE B\n");
	first = root->stack_b;
	last = ps_lstlast(root->stack_b);
	root->stack_b = first->next;
	first->prev = last;
	first->next = NULL;
	last->next = first;

	print_node(first);
	print_node(last);
}

void	rr(t_root *root)
{
	printf("RR\n");
	if (!root->stack_a && !root->stack_b)
	{
		printf("ERROR\n");
		return ;
	}
	else if (!root->stack_a)
		rotate_b(root);
	else if (!root)
		rotate_a(root);
	else
	{
		rotate_a(root);
		rotate_b(root);
	}
}

void	rrr(t_root *root)
{
	printf("RRR\n");
	if (!root->stack_a && !root->stack_b)
	{
		printf("ERROR\n");
		return ;
	}
	else if (!root->stack_a)
		reverse_rotate_b(root);
	else if (!root->stack_b)
		reverse_rotate_a(root);
	else
	{
		reverse_rotate_a(root);
		reverse_rotate_b(root);
	}

}