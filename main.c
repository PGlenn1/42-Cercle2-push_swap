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
		if (value > probe->next->value)
			return (0);
		probe = probe->next;
	}
	return (1);
}

void	sort_two(t_root *root)
{
	printf("SORT TWO\n");
	if (!is_sorted(root->stack_a))
	{
		swap_ab(root, A);
	}

}

void pick_algo(t_root *root)
{
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
	// if (root->stack_a->size == 3)
	// 	sort_simple(root);
	if (root->stack_a->size == 2)
		sort_two(root);
}

void	push_swap(char **input)
{
	t_root *root;

	root = init_root(input);
	if (!root)
		ft_error(MALLOC_FAIL);
	if (is_sorted(root->stack_a))
		ft_error(ALREADY_SORTED);
	else
		pick_algo(root);
}

int	main(int argc, char **argv)
{

	if (argc < 2)
		return (0);
	push_swap(argv);
	return (0);
}