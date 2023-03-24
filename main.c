#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_elem *probe;
	int	value;

	printf("IS SORTED ?\n");
	probe = stack->first;
	value = 0;
	while (probe && probe->next)
	{
		value = probe->value;
		if (value == probe->next->value)
			ft_error(UNWANTED_BEHAVIOR);
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
	// (void)root;
	first = stack->first->value;
	sec_last = stack->sec_last->value;
	last = stack->last->value;
	

	printf("CHOICE PATH\n");

	if (first < sec_last && sec_last < last) {
	    // first < sec_last < last
		// 2 4 6
		printf("A\n");
		rotate_ab(root, A);
		swap_ab(root, A);
	}
	else if (first < last && last < sec_last) {
	    // first < last < sec_last
		// 1 8 5
		printf("B\n");
		rev_rotate_ab(root, A);
	}
	else if (sec_last < first && first < last) {
	    // sec_last < first < last
		// 7 3 9
		printf("C\n");
		rotate_ab(root, A);
	}
	else if (sec_last < last && last < first) {
	    // sec_last < last < first
		// 20 15 18
		printf("D\n");
		swap_ab(root, A);
	}
	else if (last < first && first < sec_last) {
	    // last < first < sec_last
		// 5 6 4
		printf("E\n");
		rev_rotate_ab(root, A);
		swap_ab(root, A);
	}
	else {
		ft_error(UNWANTED_BEHAVIOR);
	}
}

int pick_algo(t_root *root)  /// LAST MUST BE SMALLEST
{
	print_both(root);
	// if (root->stack_a->size >= 500)
	// 	sort_bigger(root);
	// if (root->stack_a->size < 500)
	// 	sort_bigger(root);
	// else if (root->stack_a->size >= 100)
	// 	sort_big(root);
	// else if (root->stack_a->size < 100)
	// 	sort_big(root);
	// else if (root->stack_a->size >= 5)
	// 	sort_medium(root);
	// else if (root->stack_a->size  4)
	// 	sort_medium(root);
	// else if (root->stack_a->size <= 3)
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
		printf("Sorted\n");
	else
	{
		printf("Unsorted\n");
		return (1);
	}
	return (0);
}