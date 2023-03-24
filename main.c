#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_elem *probe;
	int	value;

	probe = stack->first;
	value = 0;
	while (probe && probe->next)
	{
		value = probe->value;
		if (value < probe->next->value)
			return (0);
		probe = probe->next;
	}
	return (1);
}

void sort_three(t_root *root, t_stack *stack)
{
	int first;
	int sec_last;
	int last;

	printf("SORT THREE\n");
	first = stack->first->value;
	sec_last = stack->sec_last->value;
	last = stack->last->value;
	
	printf("first:%d\n", first);
	printf("sec_last:%d\n", sec_last);
	printf("last:%d\n", last);

	if ( first < sec_last && first < last && sec_last < last)
	{
		rotate_ab(root, A);
		rotate_ab(root, A);
	}
	else if (sec_last < last && sec_last < first && first < last)
	{
		rotate_ab(root, A);
	}
	else if (sec_last < last < first)
		rev_rotate_ab(root, A);
	else
		ft_error(UNWANTED_BEHAVIOR);
}

int pick_algo(t_root *root)  /// LAST MUST BE SMALLEST
{
	print_both(root);
	// if (root->stack_a->size > 500)
	// 	sort_bigger(root);
	// if (root->stack_a->size == 500)
	// 	sort_bigger(root);
	// else if (root->stack_a->size > 100)
	// 	sort_big(root);
	// else if (root->stack_a->size == 100)
	// 	sort_big(root);
	// else if (root->stack_a->size > 5)
	// 	sort_medium(root);
	// else if (root->stack_a->size == 5)
	// 	sort_medium(root);
	// else if (root->stack_a->size > 3)
	// 	sort_small(root);
	if (root->stack_a->size == 3)
		sort_three(root, root->stack_a);
	print_both(root);
	if (is_sorted(root->stack_a))
		return (1);
	return (0);
}

int	push_swap(char **input)
{
	t_root *root;

	root = init_root(input);
	if (!root)
		ft_error(MALLOC_FAIL);
	if (is_sorted(root->stack_a))
		ft_error(ALREADY_SORTED);
	else if (pick_algo(root))
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{

	if (argc < 2)
		return (0);
	if (push_swap(argv))
		printf("Ok\n");
	else
		printf("Unsorted\n");
	return (0);
}