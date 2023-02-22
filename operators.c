#include "push_swap.h"

void	swap_nodes(t_stack *node_a, t_stack *node_b)
{
	t_stack *tmp;

	printf("swapping...\n");
	
	tmp = node_a->prev;
	printf("\ntmp:%p\n", tmp);
	printf("\nnode_a->next:%p\n", node_a->next);
	node_a->next = node_b->next;
	printf("node_a->next:%p\n", node_a->next);
	printf("\nnode_a->prev->next:%p\n", node_a->prev->next);
	node_a->prev->next = node_b;
	printf("node_a->prev->next:%p\n", node_a->prev->next);
	printf("\nnode_a->prev:%p\n", node_a->prev);
	node_a->prev = node_b;
	printf("node_a->prev:%p\n", node_a->prev);
    printf("\nnode_b->next:%p\n", node_b->next);
	node_b->next = node_a;
    printf("node_b->next:%p\n", node_b->next);
    printf("\nnode_b->prev:%p\n", node_b->prev);
	node_b->prev = tmp;
    printf("node_b->prev:%p\n\n", node_b->prev);
	
}

void	swap_a(t_stack *stack)
{
	t_stack	*last;

	printf("\nSWAP A\n");
	if (!stack)
		return ;
	last = ps_lstlast(stack);
	if (!stack->next)
		return ;
	printf("node[-3]:%p\n", last->prev->prev);
	printf("node[-2]:%p\n", last->prev);
	printf("node[-1]:%p\n", last);
	swap_nodes(last->prev, last);
	last = ps_lstlast(stack);
	printf("node[-3]:%p\n", last->prev->prev);
	printf("node[-2]:%p\n", last->prev);
	printf("node[-1]:%p\n", last);

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
	printf("SS\n");
	if (!root->stack_a && !root->stack_b)
		return ;
	else if (!root->stack_a)
		swap_b(root->stack_b);
	else if (!root->stack_b)
		swap_a(root->stack_a);
}