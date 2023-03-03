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
	{
		last_b->prev->next = NULL;
	}
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
	tmp = node_a->prev;
	// printf("\ntmp:%p\n", tmp);
	// printf("\nnode_a->next:%p\n", node_a->next);
	node_a->next = node_b->next;
	// printf("node_a->next:%p\n", node_a->next);
	// printf("\nnode_a->prev->next:%p\n", node_a->prev->next);
	node_a->prev->next = node_b;
	// printf("node_a->prev->next:%p\n", node_a->prev->next);
	// printf("\nnode_a->prev:%p\n", node_a->prev);
	node_a->prev = node_b;
	// printf("node_a->prev:%p\n", node_a->prev);
	// printf("\nnode_b->next:%p\n", node_b->next);
	node_b->next = node_a;
	// printf("node_b->next:%p\n", node_b->next);
	// printf("\nnode_b->prev:%p\n", node_b->prev);
	node_b->prev = tmp;
	// printf("node_b->prev:%p\n\n", node_b->prev);
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
}
